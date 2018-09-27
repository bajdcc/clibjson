//
// Project: clibjson
// Author: bajdcc
//
#ifndef CLIBJSON_PARSER_H
#define CLIBJSON_PARSER_H

#include "types.h"
#include "clexer.h"
#include "cast.h"

namespace clib {

    class cparser {
    public:
        explicit cparser(string_t str);
        ~cparser() = default;

        ast_node *parse();
        ast_node *root();

    private:
        void next();

        void program();
        ast_node *object();
        ast_node *_object();
        ast_node *_list();
        ast_node *_pair();

    private:
        void expect(bool, const string_t &);
        void match_operator(operator_t);
        void match_type(lexer_t);
        void match_number();
        void match_integer();

        void error(const string_t &);

    private:
        lexer_t base_type{l_none};

    private:
        clexer lexer;
        cast ast;
    };
}
#endif //CLIBJSON_PARSER_H