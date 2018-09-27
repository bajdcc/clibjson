//
// Project: clibjson
// Created by bajdcc
//

#include <iostream>
#include "cparser.h"

int main(int argc, char *argv[]) {
    try {
        auto json = R"(
{
  "author": "bajdcc",
  "project": "clibjson",
  "description": "json helper",
  "language": "cpp",
  "link": "https://zhuanlan.zhihu.com/learncpp",
}
)";
        clib::cparser p(json);
        auto root = p.parse();
        clib::cast::print(root, 0, std::cout);
    } catch (const std::exception& e) {
        printf("ERROR: %s\n", e.what());
    }
    return 0;
}