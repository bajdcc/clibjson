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
                break;
            case ast_obj:
                os << "{Object}";
                break;
            case ast_list:
                os << "[List]";
                break;
            case ast_pair:
                os << "(Pair)";
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

    std::ostream &operator<<(std::ostream &os, const cdom &dom) {
        dom.output(os);
        return os;
    }
}
