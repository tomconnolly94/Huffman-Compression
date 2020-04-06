#pragma once
#include <string>
#include <unordered_map>
#include <map>
#include <vector>

#include "HuffmanNode.h"

class ByteAnalysis {
public:
	static std::vector<HuffmanNode> CountByteFrequency(std::string input);
private:
	static std::vector<HuffmanNode> GetHuffmanNodes(const std::unordered_map<int, int>& map);
};