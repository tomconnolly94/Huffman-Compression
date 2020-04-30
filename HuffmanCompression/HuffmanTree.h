#pragma once
#include <unordered_map>

#include "HuffmanNode.h"

class HuffmanTree {
public:
	HuffmanTree(std::vector<HuffmanNode*> huffmanNodes);
	HuffmanTree();
	~HuffmanTree();
	HuffmanNode* AddPairOfNodes(HuffmanNode* node1, HuffmanNode* node2);
	HuffmanNode* GetRootNode();
	static void SortHuffmanNodes(std::vector<HuffmanNode*>& huffmanNodes);
	std::unordered_map<int, std::string> GenerateHuffmanCodes();
	std::string SerialiseWithNewLines();
	static std::unordered_map<int, std::string> DeserialiseFromNewLines(std::string input);
private:
	HuffmanNode* rootNode;
	std::unordered_map<int, std::string> TraverseNode(HuffmanNode* huffmanNode, std::string huffmanCode);
};