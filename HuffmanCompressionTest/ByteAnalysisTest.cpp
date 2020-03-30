#include "pch.h"
#include "CppUnitTest.h"
#include "../HuffmanCompression/ByteAnalysis.cpp"
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
			std::unordered_map<int, int> outputMap = ByteAnalysis::CountByteFrequency(input);

			Assert::AreEqual(4, (int)outputMap.size());

			Assert::AreEqual(2, outputMap[0]);
			Assert::AreEqual(1, outputMap[1]);
			Assert::AreEqual(3, outputMap[3]);
			Assert::AreEqual(4, outputMap[5]);
		}
	};
}
