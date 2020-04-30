#pragma once
//external includes
#include <string>

class HuffmanCompressor {
public:
	static void Compress(char* filePath, std::string compressedExtension, std::string huffmanCodesFileExtension);
	static void Decompress(char* filePath, std::string compressedExtension, std::string huffmanCodesFileExtension);
	static bool IsCompressing(std::string filePath, std::string compressedExtension);
private:
	static std::string GetNewFilePath(const char* filePath, std::string compressedExtension);
	static void CreateNewFile(std::string filePath);
	static bool FileExists(const std::string& filePath);
	static std::string StripExtension(std::string filePath, std::string extension);
};