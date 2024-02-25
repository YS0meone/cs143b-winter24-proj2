//
// Created by yuant on 2/24/2024.
//

#include "vm_manager.hpp"

VMManager::VMManager(const std::string& initFilePath, const std::string& inputFilePath,
                     const std::string& outputFilePath) {
    if (!fileExists(initFilePath)) {
        throw std::invalid_argument("Init file path " + initFilePath + " does not exists!");
    }
    if (!fileExists(inputFilePath)) {
        throw std::invalid_argument("Input file path " + inputFilePath + " does not exists!");
    }
    // now we assume all path exists, we initialize it with our fstream variables
    initFile.open(initFilePath.c_str());
    inputFile.open(inputFilePath.c_str());
    outputFile.open(outputFilePath.c_str());
}

VMManager::~VMManager() {
    initFile.close();
    inputFile.close();
    outputFile.close();
}

void VMManager::initializePM() {

}
