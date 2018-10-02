//
// Project: clibjson
// Created by CC
//

#ifndef CLIBJSON_CDOM_H
#define CLIBJSON_CDOM_H

#include "cast.h"

namespace clib {

    // 对象访问
    class cdom {
    public:
        explicit cdom(cast *ast, ast_node *node);
        ~cdom() = default;

        cdom(const cdom &) = default;
        cdom &operator=(const cdom &) = default;

        cdom operator[](int idx) const;
        cdom operator[](string_t idx) const;

        void output(std::ostream &os) const;

    private:
        cast *ast{nullptr};
        ast_node *node{nullptr};
    };

    std::ostream &operator<<(std::ostream &os, const cdom &dom);
}

#endif //CLIBJSON_CDOM_H
