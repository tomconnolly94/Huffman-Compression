//external includes
#include <fstream>

//internal includes
#include "HuffmanFileInterface.h"
#include "HuffmanUtil.h"

void HuffmanFileInterface::CreateNewFile(std::string filePath)
{
    std::ofstream outfile(filePath);
    outfile.close();
}

bool HuffmanFileInterface::FileExists(const std::string& filePath)
{
    struct stat buffer;
    return (stat(filePath.c_str(), &buffer) == 0);
}

std::string HuffmanFileInterface::StripExtension(std::string filePath, std::string extension)
{
    std::size_t found = filePath.find(extension);
    std::string newFilePath = filePath.substr(0, filePath.size() - extension.size());
    return newFilePath;
}

std::string HuffmanFileInterface::GetNewFilePath(const char* filePath, std::string compressedExtension)
{
    std::string newFileName;
    std::string fileString(filePath);

    if (HuffmanUtil::IsCompressing(filePath, compressedExtension)) {
        newFileName = fileString + compressedExtension;
    }
    else {
        newFileName = fileString.substr(0, fileString.size() - compressedExtension.size());
    }

    char* cnewFileName = &newFileName[0];
    return cnewFileName;
}
