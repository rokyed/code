
#include <boost/config/warning_disable.hpp>
#include <boost/wave.hpp>
#include <boost/wave/cpplexer/cpp_lex_token.hpp>
#include <boost/wave/cpplexer/cpp_lex_iterator.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_fusion.hpp>
#include <boost/spirit/include/phoenix_stl.hpp>
#include <boost/fusion/include/adapt_struct.hpp>

#include "inexor/shader/ShaderPreprocessor.hpp"

#include <vector>
#include <list>
#include <string>

using namespace boost;
using namespace boost::wave;

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

using namespace std;
using namespace inexor::shader; // we need to operate in GLOBAL SCOPE for BOOST_FUSION_ADAPT_STRUCT (which gives a list of tupels for a struct)

/// We use boost spirit qi for our parsing, since its by far the most evolved parsing writing tool atm (speed-wise, usability-wise).
/// Its syntax is inspired by the PEG (Parsing expression grammar) and may (or may not) need some further readup in the (very good) docs/tutorials
/// (however, it's hard stuff, be prepared).

// Errors: wrong shift operator (qi uses >> (!))
//         boost fusion adapt struct not in main scope
//         boost fusion adapt struct does NOT work with "using" instances -> always state the full name inside!
//         vector instead of list (use lists!)
//         list<string()> instead of list<string>()
//         ';' instead of lit(';') (better use a lit too much than one too less)

// every entry is:
// SPECIFIER(e.g.const) DATATYPE|DATATYPESIZE|[ARRAYSIZE] VARIABLENAME ;

namespace inexor {
namespace shader {

struct glsl_variable
{
    string datatype;
    string varname;
    optional<string> defaultvalue;
};

struct structure
{
    string structname;
    list<glsl_variable> variables;
};

}
}

BOOST_FUSION_ADAPT_STRUCT(
    glsl_variable,
    (std::string, datatype)
    (std::string, varname)
    (boost::optional<std::string>, defaultvalue)
)                 // Note where commas are and where not!

BOOST_FUSION_ADAPT_STRUCT(
    structure,
    (std::string, structname)
    (std::list<inexor::shader::glsl_variable>, variables)
)

namespace inexor {
namespace shader {

// *space Variabletype *space variablename *space ('=' *space initvaluecontainingspaces *space);

template <typename Iterator>
struct glsl_parser : qi::grammar<Iterator, structure(), ascii::space_type>
{
    qi::rule<Iterator, structure(), ascii::space_type> structurerule;
    qi::rule<Iterator, string(), ascii::space_type> identifier;
    qi::rule < Iterator, string(), ascii::space_type> default_value_identifier; // This contains brackets, commata and semicolons as well,
                                                                                // since you want: vec2 a = vec2(1.0, 2.0);
    qi::rule<Iterator, glsl_variable(), ascii::space_type> variable;

    glsl_parser() : glsl_parser::base_type(structurerule) // "(structurerule)" sets the starting rule for our grammar.
    {
        using qi::lit;      // attribute is inhibited (so we don't need those encapsulated values backed by the struct we parse into)
        using qi::lexeme;   // working on a single word
        using ascii::char_; // wrapper for a single char, to retain its attribute (so the output data struct gets filled with those)
        using ascii::alnum; // alphanumerical: normal letters (abcd..) + nums
        using ascii::blank; // space, tab, newline, ..

        identifier %= lexeme[+(char_("a-zA-Z_0-9") | char_('[') | char_(']'))]; // some concentated (see lexeme[..]) string with min. 1 (see "+(..)") of the allowed chars.

        default_value_identifier %= lexeme[+(alnum | char_('_') | char_('{') | char_('}')
                                             | char_('[') | char_(']') | char_('(') | char_(')')
                                             | char_('-') | char_('.') | char_(',') | blank)]; // some more allowed chars in this string here.

        // a variable looks like that:
        // type variablename (+ optionally: "= defaultvalue") ;
        variable %= (identifier >> identifier
                        >> -(lit('=') >> default_value_identifier)  // the optional (see "-(..)") default value
                        >> lit(';'));

        structurerule %=
            lit("struct")
            >> identifier
            >> lit('{')
            >> *(variable)
            >> lit('}') >> lit(';');
    }
};
}
}
void parseuniformstruct(string source) // , vector<ShaderParameter> &uniforms)
{
    using boost::spirit::ascii::space;
    typedef std::string::const_iterator iterator_type;
    typedef inexor::shader::glsl_parser<iterator_type> glsl_parser;

    glsl_parser g; // Our grammar
    iterator_type iter = source.begin(); //remember our starting iterator.
    iterator_type end = source.end();

    inexor::shader::structure emp;

    bool r = phrase_parse(iter, end, g, space, emp);

    if(r && iter == end)
    {
        char *r = "hellokitty";
        const char *da = emp.structname.c_str();
        if(emp.variables.size())
        {
            for(auto it = emp.variables.begin(); it != emp.variables.end(); ++it)
            {
                glsl_variable der = *it;
                da = der.datatype.c_str();
                da = der.varname.c_str();
                std::string *optionales = der.defaultvalue.get_ptr();
                if(optionales) da = optionales->c_str();
            }

        }
    }
    else
    {

    }
}
namespace inexor {
namespace shader {
/// The GLSLPreprocessingHooks class is used to modify the boost::wave preprocessor to work
/// with GLSL source code.
//  Although GLSL has its own preprocessor, it is limited in functionality
/// and in particular doesn't allow #include directives, which is why we want to use boost::wave.
/// However, GLSL also defines additional directives (version and extension) which would trip up
/// the wave preprocessor if we didn't give a helping hand, which is what this class is all about.
///
/// This hook has been taken from the ImageEngine/cortex project (https://github.com/ImageEngine/cortex)
///
class GLSLPreprocessingHooks : public context_policies::default_preprocessing_hooks
{
public:
    // Pass through "#version" and "#extension" directives unmodified so that they can
    // be processed by the GL preprocessor itself.
    template<typename ContextT, typename ContainerT>
    bool found_unknown_directive(const ContextT &ctx, const ContainerT &line, ContainerT &pending)
    {
        typename ContainerT::const_iterator it = line.begin();
        if(*it != boost::wave::T_POUND) return false;

        it++;
        if(it->get_value() == "version" || it->get_value() == "extension")
        {
            std::copy(line.begin(), line.end(), std::back_inserter(pending));
            return true;
        }
        return false;
    }
};

// TODO Path for filename and includepaths
std::string preprocessShader(const std::string &filename, const std::string &source)// , const std::vector<std::string> &includepaths)
{
    if(source == "") return source;

    std::string result = source + "\n";

    try {
        typedef cpplexer::lex_token<> Token;
        typedef cpplexer::lex_iterator<Token> LexIterator;
        typedef wave::context<std::string::iterator, LexIterator, iteration_context_policies::load_file_to_string, GLSLPreprocessingHooks> Context;

        Context ctx(result.begin(), result.end(), filename.c_str());

        // set the language so that #line directives aren't inserted (they make the ati shader compiler barf)
        ctx.set_language(support_normal);

        //for(auto it : includepaths) ctx.add_include_path(it.c_str());

        std::string processed = "";
        for(auto it : ctx)
        {
            const char *curtoken = it.get_value().c_str();
           // if(std::strncmp(curtoken, "main_", 5)) spawn_new_shader(curtoken+5, filename, source);
            processed += curtoken;
        }

        result = processed;
    }
    catch(boost::wave::cpp_exception &e)
    {
        // output error log here
        // or rethrow
    }
    return result;
}

} // namespace shader
} // namespace inexor

// Appendix:

// When is a uniform used?
// EASY version: glsl compilers already do that: if we compile the shader before we parse any json mapping for its inputs, we can retrieve whether this uniform
//                is used by simply checking the uniformlocation.
//                A list of used uniforms can then still be optained from the shader.

// LIBRARY VERSION:
// Use http://code.openhub.net/project?pid=&ipid=285053 to remove dead code and analyze that.

// MANUALLY:
// if its accessed inside some brackets (...) in an used path
// A used path != unused path.
// Unused path:
// Starting from the main(), each function is considered, collecting 'const' variables (note: + implicitly const values).
// Best version: traverse from main, collecting const variables, on function access
// check if the 'const' marked arguments result in the variable beeing not used
// Options: rembember all relevant if()s (with possible used code inside)
// A constant expression inside the shader 
// Note: privde a list for each debugged shader output of uniforms which have been abandoned.
// Possibly just use the compiler tutorial of boost spirit, since that would also give us meaningful error handling for free.


// TODO: traverse if another struct is used inside our materialstruct.
// TODO?: fix setting default values inside shadersettings-struct instead of uniform-call.
// TODO?: Namespaces
