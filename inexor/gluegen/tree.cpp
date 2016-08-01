#include "inexor/gluegen/tree.hpp"

namespace inexor {
namespace rpc {
namespace gluegen {

using std::unordered_map;
using std::string;


const std::unordered_map<std::string, ShTreeNode::cpp_type_t>
  ShTreeNode::type_parsers = {
    {"char*", ShTreeNode::t_cstring},
    {"float", ShTreeNode::t_float},
    {"int", ShTreeNode::t_int}
};
const std::string ShTreeNode::protoc_types[3] =
{
    "string", // t_cstring, 0
    "float",  // t_float,   1
    "int64"   // t_int,     2
};
//const std::unordered_map<ShTreeNode::cpp_type_t, std::string>
//  ShTreeNode::protoc_types = {
//    {ShTreeNode::t_cstring, "string"},
//    {ShTreeNode::t_float,   "float"},
//    {ShTreeNode::t_int,     "int64"}
//};

}
}
}
