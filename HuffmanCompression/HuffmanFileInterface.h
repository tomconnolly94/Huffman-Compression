#pragma once
//external includes
#include <string>

//internal includes
#include "FileInterface.h"

class HuffmanFileInterface : public FileInterface {
public:
	static void CreateNewFile(std::string filePath);
	static bool FileExists(const std::string& filePath);
	static std::string StripExtension(std::string filePath, std::string extension);
	static std::string GetNewFilePath(const char* filePath, std::string compressedExtension);
};