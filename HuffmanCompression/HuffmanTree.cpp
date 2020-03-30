#include <string>
#include <iostream>

#include "HuffmanTree.h"

HuffmanTree::HuffmanTree() {
	rootNode = nullptr;
}

HuffmanTree::HuffmanTree(std::unordered_map<int, int> byteFrequencies) {
	rootNode = nullptr;

	for (std::unordered_map<int, int>::value_type& x : byteFrequencies)
	{
		AddNode(x.first, x.second);
	}
}

void HuffmanTree::AddNode(int data, int frequency) {
	if (rootNode == nullptr) {
		//add first node to tree
		rootNode = new HuffmanNode(data, frequency);
		return;
	}

	HuffmanNode* newLeafNode = new HuffmanNode(data, frequency);
	HuffmanNode* newRootNode = new HuffmanNode(NULL, frequency + rootNode->frequency);
	newRootNode->left = newLeafNode;
	newRootNode->right = rootNode;

	rootNode = newRootNode;
}

HuffmanNode* HuffmanTree::GetRootNode() {
	return rootNode;
}