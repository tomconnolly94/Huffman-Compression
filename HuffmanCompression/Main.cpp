//external includes
#include <stdlib.h>
#include <set>
#include <vector>
#include <iostream>

//internal includes
#include "CompressionManager.h"

int main(int argc, char* argv[])
{
    //argument validation
    if (argc < 2) {
        std::cout << "No file provided in the command line, please provide a file to be compressed." << std::endl;
    }

    //run compression algortihm on each input file
    for (int argIndex = 1; argIndex < argc; ++argIndex) 
    {
        char* filePath = argv[argIndex];
        CompressionManager compressionManager(filePath);
        int compressionResultFlag = compressionManager.Run();
        if (compressionResultFlag > 0) return compressionResultFlag;
        return 0;
    }
}
