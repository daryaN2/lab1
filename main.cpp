#include "Counter.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "wrong input" << std::endl;
        return 0;
    }
    Counter file;
    if (!file.Count(argv[1])) {
        std::cout << "can't open file" << std::endl;
        return 0;
    }
    if (!file.Output(argv[2])) {
        std::cout << "can't open file" << std::endl;
        return 0;
    }
    return 0;
}
