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
			//dec rep = 113335555
			std::string input = "00000001 00000001 00000011 00000011 00000011 00000101 00000101 00000101 00000101";
			std::map<int, int> outputMap = ByteAnalysis::CountByteFrequency(input);

			Assert::AreEqual(256, (int)outputMap.size());
			Assert::AreEqual(2, outputMap[1]);
			Assert::AreEqual(3, outputMap[3]);
			Assert::AreEqual(4, outputMap[5]);
		}
	};
}
