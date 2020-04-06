#include <string>
#include <iostream>

#include "HuffmanTree.h"
#include <algorithm>

//sort comparison operator
struct lessThanFrequency
{
	inline bool operator() (const HuffmanNode& struct1, const HuffmanNode& struct2)
	{
		return (struct1.frequency < struct2.frequency);
	}
};

HuffmanTree::HuffmanTree() {
	rootNode = nullptr;
}

HuffmanTree::HuffmanTree(std::vector<HuffmanNode> huffmanNodes) {
	rootNode = nullptr;
	SoftHuffmanNodes(huffmanNodes);

	while(huffmanNodes.size() > 1)
	{
		HuffmanNode* rootNode = AddPairOfNodes(huffmanNodes[0], huffmanNodes[1]);
		huffmanNodes.erase(huffmanNodes.begin());
		huffmanNodes.erase(huffmanNodes.begin() + 1);
		huffmanNodes.push_back(*rootNode);
	}
}

HuffmanNode* HuffmanTree::AddPairOfNodes(HuffmanNode node1, HuffmanNode node2) 
{
	HuffmanNode* newRootNode = new HuffmanNode(NULL, node1.frequency + node2.frequency);

	rootNode = newRootNode;

	newRootNode->left = &node1;
	newRootNode->right = &node2;


	return newRootNode;
}

HuffmanNode* HuffmanTree::GetRootNode() {
	return rootNode;
}

void HuffmanTree::SoftHuffmanNodes(std::vector<HuffmanNode>& huffmanNodes)
{
	sort(huffmanNodes.begin(), huffmanNodes.end(), lessThanFrequency());
}