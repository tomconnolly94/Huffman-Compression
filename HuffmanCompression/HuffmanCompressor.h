#pragma once
//external includes
#include <string>

class HuffmanCompressor {
public:
	static void Compress(char* filePath, std::string compressedExtension, std::string huffmanCodesFileExtension);
	static bool IsCompressing(std::string filePath, std::string compressedExtension);
private:
	static std::string GetNewFilePath(char* filePath, std::string compressedExtension);
	static void CreateNewFile(std::string filePath);
};