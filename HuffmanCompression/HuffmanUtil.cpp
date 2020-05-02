//external includes
#include <map>
#include <bitset>
#include <fstream>

//internal includes
#include "HuffmanUtil.h"

std::unordered_map<std::string, int> HuffmanUtil::ReverseHuffmanCodeMap(std::unordered_map<int, std::string> huffmanCodes)
{
	std::unordered_map<std::string, int> reversedHuffmanCodes;
	for (auto const& huffmanCode : huffmanCodes)
	{
		reversedHuffmanCodes.insert(std::pair<std::string, int>(huffmanCode.second, huffmanCode.first));
	}
	return reversedHuffmanCodes;
}

bool HuffmanUtil::IsCompressing(std::string fileString, std::string compressedExtension)
{
    bool compressing = true;
    std::size_t found = fileString.find(compressedExtension);

    if (found != std::string::npos) {
        compressing = false;
    }
    return compressing;
}

int HuffmanUtil::GetFileSize(const char* filePath)
{
	FILE* pFile = NULL;
	fopen_s(&pFile, filePath, "rb");
	fseek(pFile, 0, SEEK_END);
	int Size = ftell(pFile);
	fclose(pFile);
	return Size;
}