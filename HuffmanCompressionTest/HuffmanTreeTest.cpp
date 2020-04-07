#include "pch.h"
#include "CppUnitTest.h"
#include <map>
#include <set>
#include <functional>

#include "../HuffmanCompression/HuffmanTree.cpp"
#include "../HuffmanCompression/HuffmanNode.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HuffmanCompressionTest
{
	TEST_CLASS(HuffmanTreeTest)
	{
	public:
		TEST_METHOD(AddTwoNodes)
		{
			HuffmanTree huffmanTree;
			huffmanTree.AddPairOfNodes(new HuffmanNode('a', 2), new HuffmanNode('b', 3));

			HuffmanNode* rootNode = huffmanTree.GetRootNode();

			Assert::AreEqual(5, rootNode->frequency);
			Assert::AreEqual(NULL, rootNode->data);

			Assert::AreEqual(2, rootNode->left->frequency);
			Assert::AreEqual((int)'a', rootNode->left->data);

			Assert::AreEqual(3, rootNode->right->frequency);
			Assert::AreEqual((int)'b', rootNode->right->data);
		}

		TEST_METHOD(AddFourNodes)
		{
			HuffmanTree huffmanTree;
			HuffmanNode* nodeA = new HuffmanNode('a', 2);
			HuffmanNode* nodeB = new HuffmanNode('b', 3);
			HuffmanNode* nodeC = new HuffmanNode('c', 4);
			HuffmanNode* nodeD = new HuffmanNode('d', 5);

			HuffmanNode* newRoot = huffmanTree.AddPairOfNodes(nodeA, nodeB);
			newRoot = huffmanTree.AddPairOfNodes(newRoot, nodeC);
			huffmanTree.AddPairOfNodes(newRoot, nodeD);

			HuffmanNode* rootNode = huffmanTree.GetRootNode();

			Assert::AreEqual(14, rootNode->frequency);
			Assert::AreEqual(NULL, rootNode->data);

			Assert::AreEqual(9, rootNode->left->frequency);
			Assert::AreEqual(NULL, rootNode->left->data);

			Assert::AreEqual(5, rootNode->right->frequency);
			Assert::AreEqual((int)'d', rootNode->right->data);

			Assert::AreEqual(5, rootNode->left->left->frequency);
			Assert::AreEqual(NULL, rootNode->left->left->data);

			Assert::AreEqual(4, rootNode->left->right->frequency);
			Assert::AreEqual((int)'c', rootNode->left->right->data);

			Assert::AreEqual(2, rootNode->left->left->left->frequency);
			Assert::AreEqual((int)'a', rootNode->left->left->left->data);

			Assert::AreEqual(3, rootNode->left->left->right->frequency);
			Assert::AreEqual((int)'b', rootNode->left->left->right->data);
		}


		TEST_METHOD(ConstructTreeFromList)
		{
			std::vector<HuffmanNode> sortedFrequencyVector = {
				HuffmanNode(8, 11),
				HuffmanNode(0, 1),
				HuffmanNode(15, 8),
				HuffmanNode(1, 24),
				HuffmanNode(7, 6)
			};

			HuffmanTree huffmanTree(sortedFrequencyVector);

			HuffmanNode* rootNode = huffmanTree.GetRootNode();

			Assert::AreEqual(50, rootNode->frequency);
			Assert::AreEqual(NULL, rootNode->data);

			Assert::AreEqual(24, rootNode->left->frequency);
			Assert::AreEqual(1, rootNode->left->data);

			Assert::AreEqual(26, rootNode->right->frequency);
			Assert::AreEqual(NULL, rootNode->right->data);

			Assert::AreEqual(11, rootNode->right->left->frequency);
			Assert::AreEqual(8, rootNode->right->left->data);

			Assert::AreEqual(15, rootNode->right->right->frequency);
			Assert::AreEqual(NULL, rootNode->right->right->data);

			Assert::AreEqual(8, rootNode->right->right->left->frequency);
			Assert::AreEqual(15, rootNode->right->right->left->data);

			Assert::AreEqual(7, rootNode->right->right->right->frequency);
			Assert::AreEqual(NULL, rootNode->right->right->right->data);

			Assert::AreEqual(6, rootNode->right->right->right->left->frequency);
			Assert::AreEqual(7, rootNode->right->right->right->left->data);

			Assert::AreEqual(1, rootNode->right->right->right->right->frequency);
			Assert::AreEqual(0, rootNode->right->right->right->right->data);
		}
	};
}
