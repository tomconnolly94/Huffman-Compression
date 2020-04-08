#include <string>
#include <iostream>

#include "HuffmanTree.h"
#include <algorithm>

//sort comparison operator
struct lessThanFrequency
{
	inline bool operator() (const HuffmanNode* struct1, const HuffmanNode* struct2)
	{
		return (struct1->frequency < struct2->frequency);
	}
};

HuffmanTree::HuffmanTree() 
{
	rootNode = nullptr;
}

HuffmanTree::~HuffmanTree()
{
	delete rootNode;
	//TODO: also need to traverse tree and dealloc each nodes memory
}

HuffmanTree::HuffmanTree(std::vector<HuffmanNode*> huffmanNodes) 
{
	rootNode = nullptr;

	while(huffmanNodes.size() > 1)
	{
		SortHuffmanNodes(huffmanNodes);
		HuffmanNode* rootNode = AddPairOfNodes(huffmanNodes[0], huffmanNodes[1]);
		huffmanNodes.erase(huffmanNodes.begin()); //erase huffmanNodes[0]
		huffmanNodes.erase(huffmanNodes.begin()); //erase huffmanNodes[1]
		huffmanNodes.push_back(rootNode);
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

HuffmanNode* HuffmanTree::GetRootNode() 
{
	return rootNode;
}

void HuffmanTree::SortHuffmanNodes(std::vector<HuffmanNode*>& huffmanNodes)
{
	sort(huffmanNodes.begin(), huffmanNodes.end(), lessThanFrequency());
}

std::unordered_map<int, std::string> HuffmanTree::GenerateHuffmanCodes()
{
	return TraverseNode(rootNode, "");
}

std::unordered_map<int, std::string> HuffmanTree::TraverseNode(HuffmanNode* huffmanNode, std::string huffmanCode)
{
	std::unordered_map<int, std::string> huffmanCodeMap;

	if (huffmanNode->left == nullptr && huffmanNode->right == nullptr)
	{
		huffmanCodeMap[huffmanNode->data] = huffmanCode;
	}

	if (huffmanNode->left != nullptr) {
		std::unordered_map<int, std::string> leftNodeHuffmanCodes = TraverseNode(huffmanNode->left, huffmanCode + "1");
		huffmanCodeMap.insert(leftNodeHuffmanCodes.begin(), leftNodeHuffmanCodes.end());
	}

	if (huffmanNode->right != nullptr) {
		std::unordered_map<int, std::string> rightNodeHuffmanCodes = TraverseNode(huffmanNode->right, huffmanCode + "0");
		huffmanCodeMap.insert(rightNodeHuffmanCodes.begin(), rightNodeHuffmanCodes.end());
	}

	return huffmanCodeMap;
}