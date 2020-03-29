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
			//decimal rep = 113335555
			std::string input = "00000001 00000001 00000011 00000011 00000011 00000101 00000101 00000101 00000101";
			std::vector<std::pair<int, int>> outputMap = ByteAnalysis::CountByteFrequency(input);

			Assert::AreEqual(3, (int)outputMap.size());
			Assert::AreEqual(1, outputMap[0].first);
			Assert::AreEqual(2, outputMap[0].second);

			Assert::AreEqual(3, outputMap[1].first);
			Assert::AreEqual(3, outputMap[1].second);

			Assert::AreEqual(5, outputMap[2].first);
			Assert::AreEqual(4, outputMap[2].second);
		}
	};
}
