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

HuffmanTree::~HuffmanTree() {
	delete rootNode;
	//TODO: also need to traverse tree and dealloc each nodes memory
}

HuffmanTree::HuffmanTree(std::vector<HuffmanNode> huffmanNodes) {
	rootNode = nullptr;
	SoftHuffmanNodes(huffmanNodes);

	while(huffmanNodes.size() > 1)
	{
		HuffmanNode* rootNode = AddPairOfNodes(&huffmanNodes[0], &huffmanNodes[1]);
		huffmanNodes.erase(huffmanNodes.begin()); //erase huffmanNodes[0]
		huffmanNodes.erase(huffmanNodes.begin()); //erase huffmanNodes[1]
		huffmanNodes.push_back(*rootNode);
	}
}

HuffmanNode* HuffmanTree::AddPairOfNodes(HuffmanNode* node1, HuffmanNode* node2) 
{
	HuffmanNode* newRootNode = new HuffmanNode(NULL, node1->frequency + node2->frequency);

	rootNode = newRootNode;
	rootNode->left = node1;
	rootNode->right = node2;

	return rootNode;
}

HuffmanNode* HuffmanTree::GetRootNode() {
	return rootNode;
}

void HuffmanTree::SoftHuffmanNodes(std::vector<HuffmanNode>& huffmanNodes)
{
	sort(huffmanNodes.begin(), huffmanNodes.end(), lessThanFrequency());
}