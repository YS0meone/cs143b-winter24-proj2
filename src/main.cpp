#include <fstream>
#include <iostream>
#include "vm_manager.hpp"
#include <string>
#include <stdexcept>


int main(int argc, char* argv[]) {
    std::string initPath, inputPath, outputPath;
    try {
        if (argc != 4) {
            throw std::invalid_argument("Usage: " + std::string(argv[0]) + "<init-file-path>" + "<input-file-path>" + "<output-file-path>");
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    for (unsigned i = 1; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }
    return 0;
}