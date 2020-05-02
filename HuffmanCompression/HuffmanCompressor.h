#pragma once
//external includes
#include <string>

class HuffmanCompressor {
public:
	static int Compress(const char* filePath, std::string compressedExtension, std::string huffmanCodesFileExtension);
	static int Decompress(const char* filePath, std::string compressedExtension, std::string huffmanCodesFileExtension);
};