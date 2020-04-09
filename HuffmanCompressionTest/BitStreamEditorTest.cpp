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

		TEST_METHOD(TestApplicationOfHuffmanCodesSimpleBitStream)
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

		TEST_METHOD(TestApplicationOfHuffmanCodesSimpleComplexStream)
		{
			//ascii rep = qweoqijhasdjnasd;lkujhqwretoiuhvgfaqsdf aefih[dfoij-WE0FJW#EF;@:?>
			std::string input = "0111000101110111011001010110111101110001011010010110101001101000011000010111001101100100011010100110111001100001011100110110010000111011011011000110101101110101011010100110100001110001011101110111001001100101011101000110111101101001011101010110100001110110011001110110011001100001011100010111001101100100011001100010000001100001011001010110011001101001011010000101101101100100011001100110111101101001011010100010110101010111010001010011000001000110010010100010000000111101010101110010001101000101010001100011101101000000001110100011111100111110";
			std::string expectedOutput = "1110000000000110000111101111110111001001000101011110100110110010001010111000100101100101010000110111001110000000001000000110000010000111111000011000101110101011010100111100001010111010011001001000111010111111000101001011101000001111111010100110111101110010010011010100010110001000001111001111011100110110001001110001100001001010110";

			std::unordered_map<int, std::string> huffmanCodes = {
				{105, "1111"},
				{113, "1110"},
				{97, "1001"},
				{106, "1101"},
				{104, "1100"},
				{100, "1011"},
				{102, "1010"},
				{59, "10001"},
				{117, "10000"},
				{87, "01111"},
				{103, "010101"},
				{69, "01110"},
				{70, "01101"},
				{62, "010110"},
				{118, "010111"},
				{32, "01100"},
				{91, "010100"},
				{45, "010011"},
				{61, "010000"},
				{48, "010010"},
				{74, "010001"},
				{35, "001111"},
				{107, "001010"},
				{64, "001110"},
				{110, "001101"},
				{58, "001100"},
				{114, "001000"},
				{108, "001011"},
				{63, "001001"},
				{101, "00011"},
				{115, "00010"},
				{111, "00001"},
				{119, "000000"},
				{116, "000001"}
			};

			std::string outputBitStream = BitStreamEditor::ApplyHuffmanCodes(input, huffmanCodes);

			Assert::AreEqual(expectedOutput, outputBitStream);
		}
	};
}
