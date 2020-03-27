#pragma once
#include <map>
#include "HuffmanNode.h"

class HuffmanTree {
public:
	HuffmanTree(std::map<int, int> byteFrequency);
	HuffmanTree();
	void AddNode(int data);
	HuffmanNode* GetRootNode();
private:
	HuffmanNode* rootNode;
};