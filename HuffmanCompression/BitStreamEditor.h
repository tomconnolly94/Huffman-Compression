#pragma once
//external includes
#include <string>
#include <vector>
#include <unordered_map>

class BitStreamEditor {
public:
	static std::string ApplyHuffmanCodes(std::string inputBitStream, std::unordered_map<int, std::string> huffmanCodes);
	static std::string ReverseHuffmanCodes(std::string compressedBitStream, std::unordered_map<std::string, int> huffmanCodes);
};