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
		TEST_METHOD(AddOneNode)
		{
			HuffmanTree huffmanTree;
			huffmanTree.AddNode('a', 2);

			HuffmanNode* rootNode = huffmanTree.GetRootNode();

			Assert::AreEqual((int)'a', rootNode->data);
			Assert::AreEqual(2, rootNode->frequency);
		}

		TEST_METHOD(AddTwoNodes)
		{
			HuffmanTree huffmanTree;
			huffmanTree.AddNode('a', 2);
			huffmanTree.AddNode('b', 3);

			HuffmanNode* rootNode = huffmanTree.GetRootNode();

			Assert::AreEqual(5, rootNode->frequency);
			Assert::AreEqual(NULL, rootNode->data);

			Assert::AreEqual(3, rootNode->left->frequency);
			Assert::AreEqual((int)'b', rootNode->left->data);

			Assert::AreEqual(2, rootNode->right->frequency);
			Assert::AreEqual((int)'a', rootNode->right->data);
		}

		TEST_METHOD(AddFourNodes)
		{
			HuffmanTree huffmanTree;
			huffmanTree.AddNode('a', 2);
			huffmanTree.AddNode('b', 3);
			huffmanTree.AddNode('c', 4);
			huffmanTree.AddNode('d', 5);

			HuffmanNode* rootNode = huffmanTree.GetRootNode();

			Assert::AreEqual(14, rootNode->frequency);
			Assert::AreEqual(NULL, rootNode->data);

			Assert::AreEqual(5, rootNode->left->frequency);
			Assert::AreEqual((int)'d', rootNode->left->data);

			Assert::AreEqual(9, rootNode->right->frequency);
			Assert::AreEqual(NULL, rootNode->right->data);

			Assert::AreEqual(4, rootNode->right->left->frequency);
			Assert::AreEqual((int)'c', rootNode->right->left->data);

			Assert::AreEqual(5, rootNode->right->right->frequency);
			Assert::AreEqual(NULL, rootNode->right->right->data);

			Assert::AreEqual(3, rootNode->right->right->left->frequency);
			Assert::AreEqual((int)'b', rootNode->right->right->left->data);

			Assert::AreEqual(2, rootNode->right->right->right->frequency);
			Assert::AreEqual((int)'a', rootNode->right->right->right->data);
		}


		TEST_METHOD(ConstructFromFrequencyVector)
		{
			std::unordered_map<int, int> sortedFrequencyVector = {
				{0, 1},
				{7, 6},
				{15, 8},
				{8, 11},
				{1, 24}
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
