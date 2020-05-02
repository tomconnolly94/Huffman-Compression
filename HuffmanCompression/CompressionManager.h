#pragma once

//external includes
#include <string>

//internal includes
#include "CompressionAnalysis.h"

class CompressionManager {
public:
    CompressionManager(const char* filePath);
    int Run();
private:
    std::string compressedExtension = ".huffCompressed";
    std::string huffmanCodesFileExtension = ".huffCodes";
    const char* filePath;
    CompressionAnalysis compressionAnalysis;
    CompressionAnalysis::CompressionOperation compressionOperation;
    int operationSuccess;
};