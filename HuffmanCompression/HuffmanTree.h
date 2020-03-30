#pragma once
#include <unordered_map>

#include "HuffmanNode.h"

class HuffmanTree {
public:
	HuffmanTree(std::unordered_map<int, int> byteFrequency);
	HuffmanTree();
	void AddNode(int data, int frequency);
	HuffmanNode* GetRootNode();
private:
	HuffmanNode* rootNode;
};