#pragma once
//external includes
#include <string>
#include <unordered_map>
#include <map>
#include <vector>

//internal includes
#include "HuffmanNode.h"

class BitStreamAnalysis {
public:
	static std::vector<HuffmanNode*> CountByteFrequency(std::string input);
private:
	static std::vector<HuffmanNode*> GetHuffmanNodes(const std::unordered_map<int, int>& map);
};