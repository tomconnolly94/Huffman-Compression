//external includes
#include <iostream>
//external includes
#include <stdlib.h>
#include <set>
#include <vector>

//internal includes
#include "HuffmanCompressor.h"
#include "Util.h"


int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cout << "No file provided in the command line, please provide a file to be compressed." << std::endl;
    }

    for (int argIndex = 1; argIndex < argc; ++argIndex) {

        char* filePath = argv[argIndex];
        std::string compressedExtension = ".huffCompressed";
        std::string huffmanCodesFileExtension = ".huffmanCodes";

        if (Util::IsCompressing(filePath, compressedExtension))
        {
            HuffmanCompressor::Compress(filePath, compressedExtension, huffmanCodesFileExtension);
        }
        else
        {
            HuffmanCompressor::Decompress(filePath, compressedExtension, huffmanCodesFileExtension);
        }
    }
}
