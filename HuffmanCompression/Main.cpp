#include <iostream>
#include <unordered_map>
#include "FileInterface.h"
#include "BitStreamAnalysis.h"
#include "HuffmanCompressor.h"


int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cout << "No file provided in the command line, please provide a file to be encrypted." << std::endl;
    }

    for (int argIndex = 1; argIndex < argc; ++argIndex) {

        char* filePath = argv[argIndex];

        HuffmanCompressor::Compress(filePath);

    }
}