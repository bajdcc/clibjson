//
// Project: clibjson
// Created by CC
//

#include <iostream>
#include "cdom.h"
#include "cast.h"

namespace clib {

    cdom::cdom(cast *ast, ast_node *node)
            : ast(ast), node(node) {}

    cdom cdom::operator[](int idx) const {
        if (node->flag == ast_list) {
            auto _node = cast::index(node, idx);
            if (_node)
                return cdom{ast, _node};
        }
        printf("cdom: invalid index %d\n", idx);
        throw std::exception();
    }

    cdom cdom::operator[](string_t idx) const {
        if (node->flag == ast_obj) {
            auto _node = cast::index(node, idx);
            if (_node)
                return cdom{ast, _node};
        }
        printf("cdom: invalid index '%s'\n", idx.c_str());
        throw std::exception();
    }

    void cdom::output(std::ostream &os) const {
        if (node == nullptr)
            return;
        auto type = (ast_t) node->flag;
        switch (type) {
            case ast_root:
            case ast_obj:
            case ast_list:
            case ast_pair:
                clib::cast::print(node, 0, std::cout);
                break;
            case ast_string:
                os << node->data._string;
                break;
            case ast_char:
                os << node->data._char;
                break;
            case ast_uchar:
                os << node->data._uchar;
                break;
            case ast_short:
                os << node->data._short;
                break;
            case ast_ushort:
                os << node->data._ushort;
                break;
            case ast_int:
                os << node->data._int;
                break;
            case ast_uint:
                os << node->data._uint;
                break;
            case ast_long:
                os << node->data._long;
                break;
            case ast_ulong:
                os << node->data._ulong;
                break;
            case ast_float:
                os << node->data._float;
                break;
            case ast_double:
                os << node->data._double;
                break;
        }
    }

#define DEFINE_NODE_ASSIGN(t) cdom &cdom::operator=(const LEX_T(t) &v) { \
    node->flag = ast_##t; \
    node->data._##t = v; \
    return *this; }

    DEFINE_NODE_ASSIGN(char)
    DEFINE_NODE_ASSIGN(uchar)
    DEFINE_NODE_ASSIGN(short)
    DEFINE_NODE_ASSIGN(ushort)
    DEFINE_NODE_ASSIGN(int)
    DEFINE_NODE_ASSIGN(uint)
    DEFINE_NODE_ASSIGN(long)
    DEFINE_NODE_ASSIGN(ulong)
    DEFINE_NODE_ASSIGN(float)
    DEFINE_NODE_ASSIGN(double)
#undef DEFINE_NODE_DATA

    cdom &cdom::operator=(const string_t &v) {
        node->flag = ast_string;
        ast->set_str(node, v);
        return *this;
    }

    std::ostream &operator<<(std::ostream &os, const cdom &dom) {
        dom.output(os);
        return os;
    }
}
