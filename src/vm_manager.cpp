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
    int segmentID;
    int segmentSize;
    int ptFrame;
    std::string line1;
    if (!std::getline(initFile, line1)){
        throw std::invalid_argument("Init file empty!");
    }
    std::istringstream iss1(line1);
    // initialize the ST part
    while (iss1 >> segmentID >> segmentSize >> ptFrame) {
        setSegmentTable(segmentID, segmentSize, ptFrame);
    }

    int pageOffset;
    int frameID;
    std::string line2;
    if (!std::getline(initFile, line2)){
        throw std::invalid_argument("Init file does not have PT configuration!");
    }
    std::istringstream iss2(line2);
    // initialize the PT part
    while (iss2 >> segmentID >> pageOffset >> frameID) {
        setPageTable(segmentID, pageOffset, frameID);
    }

}

void VMManager::printST() {
    for (unsigned i = 0; i < 2 * PAGE_SIZE; i += 2) {
        if (pm[i] != 0) {
            std::cout << "Segment " << i / 2 << ": (" << pm[i] << ", " << pm[i+1] << ")" << std::endl;
        }
    }
}


void VMManager::setSegmentTable(int segmentID, int segmentSize, int ptFrame) {
    pm[2 * segmentID] = segmentSize;
    pm[2 * segmentID + 1] = ptFrame;
}

void VMManager::setPageTable(int segmentID, int pageOffset, int frameID) {
    pm[pm[2 * segmentID + 1] * PAGE_SIZE + pageOffset] = frameID;
}

void VMManager::printPT(int segmentID) {
    std::cout << "Page table of segment " << segmentID << std::endl;
    int offset = pm[2 * segmentID + 1] * PAGE_SIZE;
    for (unsigned i = 0; i < PAGE_SIZE; ++i) {
        // check if the page entry exists
        if (pm[offset + i] != 0) {
            std::cout << "Table entry " << i << ": " << pm[offset + i] << std::endl;
        }
    }
}

int VMManager::translateVA(int virtualAddress) {
    int s = (virtualAddress >> 18) & 0x1FF;
    int p = (virtualAddress >> 9) & 0x1FF;
    int w = virtualAddress & 0x1FF;
    int pw = virtualAddress & 0x3FFFF;
    if (pw >= pm[2 * s]) {
        return -1;
//        throw std::invalid_argument("Try to access beyond the segment size!");
    }
    int pa = pm[pm[2 * s + 1] * PAGE_SIZE + p] * PAGE_SIZE + w;
    return pa;
}

void VMManager::translate() {
    int virtualAddress;
    while (inputFile >> virtualAddress){
        translateVA(virtualAddress);
    }
}

