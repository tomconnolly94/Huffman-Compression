#pragma once
#include <string>

class FileInterface {
public:
	static std::string ReadFileAsBits(std::string filePath);
	static void WriteBitsToFile(std::string bitstring, const char* file);
private:
};
