#include "vm_manager.hpp"


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
    initPath = std::string(argv[1]);
    inputPath = std::string(argv[2]);
    outputPath = std::string(argv[3]);
    try {
        VMManager vmm(initPath, inputPath, outputPath);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}