#include <iostream>
#include <unordered_map>
#include "FileInterface.h"
#include "ByteAnalysis.h"


int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cout << "No file provided in the command line, please provide a file to be encrypted." << std::endl;
    }

    for (int argIndex = 1; argIndex < argc; ++argIndex) {

        char* file = argv[argIndex];

        std::string bitStream = FileInterface::ReadFileAsBits(file);
        std::unordered_map<int, int> byteFrequencyCount = ByteAnalysis::CountByteFrequency(bitStream);


    }
}