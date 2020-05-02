#pragma once

//external includes
#include <string>
#include <vector>
#include <unordered_map>

//internal includes
#include "../CppCommonTProj/CppCommonTProj/Util.h"

class HuffmanUtil : public Util {
public:
	static std::unordered_map<std::string, int> ReverseHuffmanCodeMap(std::unordered_map<int, std::string> huffmanCodes);
	static bool IsCompressing(std::string fileString, std::string compressedExtension);
};