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
#include <sstream>
#include <cstdlib>
#include <list>
#include <algorithm>

const int PAGE_SIZE = 512;
const unsigned NUM_OF_PAGES = 1024;
const unsigned PM_SIZE = PAGE_SIZE * NUM_OF_PAGES;

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



    void setSegmentTable(int segmentID, int segmentSize, int ptFrame);

    void setPageTable(int segmentID, int pageOffset, int frameID);

    void translate();

    int translateVA(int virtualAddress);

    void readBlock(int blockID, int pmDest);
    // for debug use
    void printST();

    void printPT(int segmentID);

private:
    std::ifstream initFile;
    std::ifstream inputFile;
    std::ofstream outputFile;

    int pm[PM_SIZE] = {0};
    int pd[NUM_OF_PAGES][PAGE_SIZE] = {0};
    std::list<int> freeFrames;
    void initializePM();
};


#endif //VMM_VM_MANAGER_HPP
