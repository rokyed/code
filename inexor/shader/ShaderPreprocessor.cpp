
#include <boost/wave.hpp>
#include "boost/wave/cpplexer/cpp_lex_token.hpp"
#include "boost/wave/cpplexer/cpp_lex_iterator.hpp"

#include <string>
using namespace boost::wave;

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
    //..todo, maybe we want to improve debug-output of shaders, by noticing the glsl compiler
    //  on file changes.
    //template <typename ContextT>
    //void opened_include_file(ContextT const& ctx, std::string const& relname,
    //    std::string const& absname, bool is_system_include)
    //{
    //    ctx.add_macro_definition("#pragma Line File").. <- But this will get cut away.
    //}
};

// TODO Path for filename and includepaths
std::string preprocessShader(const std::string &filename, const std::string &source)// , const std::vector<std::string> &includepaths)
{
    if(source == "") return source;

    std::string result = source + "\n";

    try {
        typedef cpplexer::lex_token<> Token;
        typedef cpplexer::lex_iterator<Token> LexIterator;
        typedef context<std::string::iterator, LexIterator, iteration_context_policies::load_file_to_string, GLSLPreprocessingHooks> Context;

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
        // rethrow but in a nicely formatted form
        //throw Exception(boost::str(boost::format("Error during preprocessing : %s line %d : %s") % fileName % e.line_no() % e.description()));
    }
    return result;
}

} // namespace shader
} // namespace inexor
