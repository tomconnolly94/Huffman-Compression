#pragma once
#include <unordered_map>

#include "HuffmanNode.h"

class HuffmanTree {
public:
	HuffmanTree(std::vector<HuffmanNode> byteFrequencies);
	HuffmanTree();
	HuffmanNode* AddPairOfNodes(HuffmanNode* node1, HuffmanNode* node2);
	HuffmanNode* GetRootNode();
	static void SoftHuffmanNodes(std::vector<HuffmanNode>& huffmanNodes);
	~HuffmanTree();
private:
	HuffmanNode* rootNode;
};