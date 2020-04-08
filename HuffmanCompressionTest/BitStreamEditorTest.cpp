#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <unordered_map>

#include "../HuffmanCompression/BitStreamEditor.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HuffmanCompressionTest
{
	TEST_CLASS(BitStreamEditorTest)
	{
	public:

		TEST_METHOD(TestApplicationOfHuffmanCodes)
		{
			//decimal rep = 0133355550
			std::string input = "00000000000000010000001100000011000000110000010100000101000001010000010100000000";
			std::string expectedOutput = "000100101010111110001";

			std::unordered_map<int, std::string> huffmanCodes = {
				{5, "1"},
				{3, "01"},
				{1, "001"},
				{0, "0001"}
			};

			std::string outputBitStream = BitStreamEditor::ApplyHuffmanCodes(input, huffmanCodes);

			Assert::AreEqual(expectedOutput, outputBitStream);
		}
	};
}
