#include "pch.h"
#include "CppUnitTest.h"
#include "../HuffmanCompression/BitStreamAnalysis.cpp"
#include "../HuffmanCompression/Util.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HuffmanCompressionTest
{
	TEST_CLASS(ByteAnalysisTest)
	{
	public:

		TEST_METHOD(CountByteFrequencies)
		{
			//decimal rep = 0133355550
			std::string input = "00000000000000010000001100000011000000110000010100000101000001010000010100000000";
			std::vector<HuffmanNode*> outputMap = BitStreamAnalysis::CountByteFrequency(input);

			Assert::AreEqual(4, (int)outputMap.size());

			Assert::AreEqual(1, outputMap[0]->data);
			Assert::AreEqual(1, outputMap[0]->frequency);

			Assert::AreEqual(0, outputMap[1]->data);
			Assert::AreEqual(2, outputMap[1]->frequency);

			Assert::AreEqual(3, outputMap[2]->data);
			Assert::AreEqual(3, outputMap[2]->frequency);
			
			Assert::AreEqual(5, outputMap[3]->data);
			Assert::AreEqual(4, outputMap[3]->frequency);
		}
	};
}
