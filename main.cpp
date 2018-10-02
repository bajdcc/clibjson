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
  "test": {
    "list_1": [1, 2, 3, 4, 5],
    "list_2": [[], [[]], [[], []]]
  }
}
)";
        clib::cparser p(json);
        auto root = p.parse();
        clib::cast::print(root, 0, std::cout);
        std::cout << std::endl;
        auto dom = p.obj();
        std::cout << "Author: " << dom["author"] << std::endl;
        auto test = dom["test"];
        std::cout << "Test_1: " << test["list_1"][4] << std::endl;
        test["list_1"][3] = 6;
        test["list_1"][4] = "test";
        std::cout << test << std::endl;
    } catch (const std::exception& e) {
        printf("ERROR: %s\n", e.what());
    }
    return 0;
}