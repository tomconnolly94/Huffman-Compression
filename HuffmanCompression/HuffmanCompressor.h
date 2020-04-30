#pragma once
//external includes
#include <string>

class HuffmanCompressor {
public:
	static void Compress(char* filePath, std::string compressedExtension, std::string huffmanCodesFileExtension);
	static void Decompress(char* filePath, std::string compressedExtension, std::string huffmanCodesFileExtension);
};