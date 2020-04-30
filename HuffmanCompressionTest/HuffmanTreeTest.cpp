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
		TEST_METHOD(TestAddTwoNodes)
		{
			HuffmanTree huffmanTree;
			HuffmanNode nodeA('a', 2);
			HuffmanNode nodeB('b', 3);
			huffmanTree.AddPairOfNodes(&nodeA, &nodeB);

			HuffmanNode* rootNode = huffmanTree.GetRootNode();

			Assert::AreEqual(5, rootNode->frequency);
			Assert::AreEqual(NULL, rootNode->data);

			Assert::AreEqual(2, rootNode->left->frequency);
			Assert::AreEqual((int)'a', rootNode->left->data);

			Assert::AreEqual(3, rootNode->right->frequency);
			Assert::AreEqual((int)'b', rootNode->right->data);
		}

		TEST_METHOD(TestAddFourNodes)
		{
			HuffmanTree huffmanTree;
			HuffmanNode nodeA('a', 2);
			HuffmanNode nodeB('b', 3);
			HuffmanNode nodeC('c', 4);
			HuffmanNode nodeD('d', 5);

			HuffmanNode* newRoot = huffmanTree.AddPairOfNodes(&nodeA, &nodeB);
			newRoot = huffmanTree.AddPairOfNodes(newRoot, &nodeC);
			huffmanTree.AddPairOfNodes(newRoot, &nodeD);

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

		TEST_METHOD(TestSimpleTreeConstruction)
		{
			HuffmanNode huffmanNodeA(8, 11);
			HuffmanNode huffmanNodeB(0, 1);
			HuffmanNode huffmanNodeC(15, 8);
			HuffmanNode huffmanNodeD(1, 24);
			HuffmanNode huffmanNodeE(7, 6);

			std::vector<HuffmanNode*> huffmanNodes = {
				&huffmanNodeA,
				&huffmanNodeB,
				&huffmanNodeC,
				&huffmanNodeD,
				&huffmanNodeE
			};

			HuffmanTree huffmanTree(huffmanNodes);

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

			Assert::AreEqual(7, rootNode->right->right->left->frequency);
			Assert::AreEqual(NULL, rootNode->right->right->left->data);

			Assert::AreEqual(8, rootNode->right->right->right->frequency);
			Assert::AreEqual(15, rootNode->right->right->right->data);

			Assert::AreEqual(1, rootNode->right->right->left->left->frequency);
			Assert::AreEqual(0, rootNode->right->right->left->left->data);

			Assert::AreEqual(6, rootNode->right->right->left->right->frequency);
			Assert::AreEqual(7, rootNode->right->right->left->right->data);
		}

		TEST_METHOD(TestComplexTreeConstruction)
		{
			HuffmanNode huffmanNodeB(39, 7);
			HuffmanNode huffmanNodeC(4, 8);
			HuffmanNode huffmanNodeF(41, 78);
			HuffmanNode huffmanNodeA(27, 6);
			HuffmanNode huffmanNodeE(69, 24);
			HuffmanNode huffmanNodeD(3, 9);

			std::vector<HuffmanNode*> huffmanNodes = {
				&huffmanNodeA,
				&huffmanNodeB,
				&huffmanNodeC,
				&huffmanNodeD,
				&huffmanNodeE,
				&huffmanNodeF
			};

			HuffmanTree huffmanTree(huffmanNodes);

			HuffmanNode* rootNode = huffmanTree.GetRootNode();

			Assert::AreEqual(132, rootNode->frequency);
			Assert::AreEqual(NULL, rootNode->data);

			Assert::AreEqual(54, rootNode->left->frequency);
			Assert::AreEqual(NULL, rootNode->left->data);

			Assert::AreEqual(78, rootNode->right->frequency);
			Assert::AreEqual(41, rootNode->right->data);

			Assert::AreEqual(24, rootNode->left->left->frequency);
			Assert::AreEqual(69, rootNode->left->left->data);

			Assert::AreEqual(30, rootNode->left->right->frequency);
			Assert::AreEqual(NULL, rootNode->left->right->data);

			Assert::AreEqual(13, rootNode->left->right->left->frequency);
			Assert::AreEqual(NULL, rootNode->left->right->left->data);

			Assert::AreEqual(17, rootNode->left->right->right->frequency);
			Assert::AreEqual(NULL, rootNode->left->right->right->data);

			Assert::AreEqual(6, rootNode->left->right->left->left->frequency);
			Assert::AreEqual(27, rootNode->left->right->left->left->data);

			Assert::AreEqual(7, rootNode->left->right->left->right->frequency);
			Assert::AreEqual(39, rootNode->left->right->left->right->data);

			Assert::AreEqual(8, rootNode->left->right->right->left->frequency);
			Assert::AreEqual(4, rootNode->left->right->right->left->data);

			Assert::AreEqual(9, rootNode->left->right->right->right->frequency);
			Assert::AreEqual(3, rootNode->left->right->right->right->data);
		}

		TEST_METHOD(TestHuffmanCodeGeneration)
		{
			HuffmanNode huffmanNodeB(39, 7);
			HuffmanNode huffmanNodeC(4, 8);
			HuffmanNode huffmanNodeF(41, 78);
			HuffmanNode huffmanNodeA(27, 6);
			HuffmanNode huffmanNodeE(69, 24);
			HuffmanNode huffmanNodeD(3, 9);

			std::vector<HuffmanNode*> huffmanNodes = {
				&huffmanNodeA,
				&huffmanNodeB,
				&huffmanNodeC,
				&huffmanNodeD,
				&huffmanNodeE,
				&huffmanNodeF
			};

			HuffmanTree huffmanTree(huffmanNodes);

			std::unordered_map<int, std::string> huffmanCodeMap = huffmanTree.GenerateHuffmanCodes();
			
			std::unordered_map<int, std::string> expectedHuffmanCodeMap = {
				{69, "11"},
				{3, "1000"},
				{27, "1011"},
				{39, "1010"},
				{4, "1001"},
				{41, "0"}
			};

			Assert::AreEqual(expectedHuffmanCodeMap.size(), huffmanCodeMap.size());

			for (size_t index = 0; index < expectedHuffmanCodeMap.size(); ++index)
			{
				Assert::AreEqual(expectedHuffmanCodeMap[index], huffmanCodeMap[index]);
			}
		}

		TEST_METHOD(TestHuffmanTreeSerialisiation)
		{
			HuffmanNode huffmanNodeB(39, 7);
			HuffmanNode huffmanNodeC(4, 8);
			HuffmanNode huffmanNodeF(41, 78);
			HuffmanNode huffmanNodeA(27, 6);
			HuffmanNode huffmanNodeE(69, 24);
			HuffmanNode huffmanNodeD(3, 9);

			std::vector<HuffmanNode*> huffmanNodes = {
				&huffmanNodeA,
				&huffmanNodeB,
				&huffmanNodeC,
				&huffmanNodeD,
				&huffmanNodeE,
				&huffmanNodeF
			};

			HuffmanTree huffmanTree(huffmanNodes);

			std::string serialisedHuffmanCodes = huffmanTree.SerialiseWithNewLines();
			
			std::string expectedSerialisedHuffmanCodes = "69\n11\n3\n1000\n27\n1011\n39\n1010\n4\n1001\n41\n0\n";

			Assert::AreEqual(expectedSerialisedHuffmanCodes, serialisedHuffmanCodes);
		}

		TEST_METHOD(TestReadNewLineFileContent)
		{
			std::string inputNewLineFileContent = "117\n1011\n53\n1101011100\n101\n111\n48\n1000010100\n112\n11011\n68\n11010111111\n106\n1101011101\n114\n00000";
			std::unordered_map<int, std::string> expectedHuffmanCodes =
			{ 
				{117, "1011"},
				{53, "1101011100"},
				{101, "111"},
				{48, "1000010100"},
				{112, "11011"},
				{68, "11010111111"},
				{106, "1101011101"},
				{114, "00000"},
			};

			std::unordered_map<int, std::string> huffmanCodes = HuffmanTree::DeserialiseFromNewLines(inputNewLineFileContent);

			Assert::AreEqual(expectedHuffmanCodes.size(), huffmanCodes.size());

			for (int huffmanIndex = 0; huffmanIndex < expectedHuffmanCodes.size(); ++huffmanIndex)
			{
				Assert::AreEqual(expectedHuffmanCodes[huffmanIndex], huffmanCodes[huffmanIndex]);
			}
		}
	};
}
