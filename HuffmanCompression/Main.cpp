//external includes
#include <iostream>
#include <stdlib.h>
#include <set>
#include <vector>

//internal includes
#include "HuffmanCompressor.h"
#include "HuffmanUtil.h"
#include "HuffmanFileInterface.h"


int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cout << "No file provided in the command line, please provide a file to be compressed." << std::endl;
    }

    for (int argIndex = 1; argIndex < argc; ++argIndex) {

        char* filePath = argv[argIndex];
        std::string compressedExtension = ".huffCompressed";
        std::string huffmanCodesFileExtension = ".huffCodes";

        //ensure filePath exists
        if(!HuffmanFileInterface::FileExists(filePath))
        {
            std::cout << "ERROR: Input file does not exist! Please provide the software with a file that exists on disk." << std::endl;
            return 1;
        }

        if (HuffmanUtil::IsCompressing(filePath, compressedExtension))
        {
            return HuffmanCompressor::Compress(filePath, compressedExtension, huffmanCodesFileExtension);
        }
        else
        {
            return HuffmanCompressor::Decompress(filePath, compressedExtension, huffmanCodesFileExtension);
        }
        
    }
}
