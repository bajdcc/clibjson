//
// Project: clibjson
// Created by bajdcc
//

#include <iostream>
#include "cparser.h"

int main(int argc, char *argv[]) {
    try {
        clib::cparser p("[{'r':6},[1,2,3,4,5],2]");
        auto root = p.parse();
        clib::cast::print(root, 0, std::cout);
    } catch (const std::exception& e) {
        printf("ERROR: %s\n", e.what());
    }
    return 0;
}