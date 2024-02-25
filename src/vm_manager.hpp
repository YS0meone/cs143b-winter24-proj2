//
// Created by yuant on 2/24/2024.
//

#ifndef VMM_VM_MANAGER_HPP
#define VMM_VM_MANAGER_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <sys/stat.h>
#include <fstream>

class VMManager {
public:
    VMManager(
            const std::string& initFilePath,
            const std::string& inputFilePath,
            const std::string& outputFilePath);

    inline bool fileExists(const std::string fileName) {
        struct stat buffer;
        return (stat(fileName.c_str(), &buffer) == 0);
    }

    ~VMManager();

    void initializePM();

private:
    std::ifstream initFile;
    std::ifstream inputFile;
    std::ofstream outputFile;
};


#endif //VMM_VM_MANAGER_HPP
