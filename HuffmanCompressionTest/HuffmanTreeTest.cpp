#include "pch.h"
#include "CppUnitTest.h"
#include "../HuffmanCompression/HuffmanTree.cpp"
#include "../HuffmanCompression/HuffmanNode.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HuffmanTreeTest
{
	TEST_CLASS(HuffmanTreeTest)
	{
	public:

		TEST_METHOD(AddOneNode)
		{
			HuffmanTree huffmanTree;
			huffmanTree.AddNode(2);

			HuffmanNode* rootNode = huffmanTree.GetRootNode();

			Assert::AreEqual(2, rootNode->data);
		}

		TEST_METHOD(AddTwoNodes)
		{
			HuffmanTree huffmanTree;
			huffmanTree.AddNode(2);
			huffmanTree.AddNode(3);

			HuffmanNode* rootNode = huffmanTree.GetRootNode();

			Assert::AreEqual(5, rootNode->data);
			Assert::AreEqual(3, rootNode->left->data);
			Assert::AreEqual(2, rootNode->right->data);
		}

		TEST_METHOD(AddFourNodes)
		{
			HuffmanTree huffmanTree;
			huffmanTree.AddNode(2);
			huffmanTree.AddNode(3);
			huffmanTree.AddNode(4);
			huffmanTree.AddNode(5);

			HuffmanNode* rootNode = huffmanTree.GetRootNode();

			Assert::AreEqual(14, rootNode->data);
			Assert::AreEqual(5, rootNode->left->data);

			Assert::AreEqual(9, rootNode->right->data);
			Assert::AreEqual(4, rootNode->right->left->data);

			Assert::AreEqual(5, rootNode->right->right->data);
			Assert::AreEqual(3, rootNode->right->right->left->data);
			Assert::AreEqual(2, rootNode->right->right->right->data);
		}
	};
}
