#include <string>
#include <iostream>
#include "HuffmanTree.h"

HuffmanTree::HuffmanTree() {
	rootNode = nullptr;
}


HuffmanTree::HuffmanTree(std::map<int, int> byteFrequencies) {


	for (std::map<int, int>::value_type& x : byteFrequencies)
	{
		std::cout << x.first << "," << x.second << std::endl;
	}
	rootNode = nullptr;
}

void HuffmanTree::AddNode(int data) {
	if (rootNode == nullptr) {
		//add first node to tree
		rootNode = new HuffmanNode(data);
		return;
	}

	HuffmanNode* newLeafNode = new HuffmanNode(data);
	HuffmanNode* newRootNode = new HuffmanNode(data + rootNode->data);
	newRootNode->left = newLeafNode;
	newRootNode->right = rootNode;

	rootNode = newRootNode;
}

HuffmanNode* HuffmanTree::GetRootNode() {
	return rootNode;
}