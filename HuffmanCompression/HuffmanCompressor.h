#pragma once
//external includes
#include <string>

class HuffmanCompressor {
public:
	static int Compress(char* filePath, std::string compressedExtension, std::string huffmanCodesFileExtension);
	static int Decompress(char* filePath, std::string compressedExtension, std::string huffmanCodesFileExtension);
};