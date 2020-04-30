#pragma once
#include <string>
#include <vector>
#include <unordered_map>

class Util {
public:
	static int ConvertBinaryToDecimal(std::string strInput);
	static std::unordered_map<std::string, int> ReverseHuffmanCodeMap(std::unordered_map<int, std::string> huffmanCodes);
	static std::string ConvertDecimalToBinary(int strInput, int requiredLength);
};