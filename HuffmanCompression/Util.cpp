//external includes
#include <map>
#include <bitset>

//internal includes
#include "Util.h"

int Util::ConvertBinaryToDecimal(std::string strInput)
{
	long long input = std::stoll(strInput);

	int decimalNumber = 0, i = 0, remainder;
	while (input != 0)
	{
		remainder = input % 10;
		input /= 10;
		decimalNumber += remainder * (int)pow(2, i);
		++i;
	}
	return decimalNumber;
}

std::string Util::ConvertDecimalToBinary(int strInput, int requiredLength)
{
	const int initialBitNum = 8;
	int bitsToCull = initialBitNum - requiredLength;

	std::string output = std::bitset<initialBitNum>(int(strInput)).to_string();
	output = output.substr(bitsToCull);

	return output;
}


std::unordered_map<std::string, int> Util::ReverseHuffmanCodeMap(std::unordered_map<int, std::string> huffmanCodes)
{
	std::unordered_map<std::string, int> reversedHuffmanCodes;
	for (auto const& huffmanCode : huffmanCodes)
	{
		reversedHuffmanCodes.insert(std::pair<std::string, int>(huffmanCode.second, huffmanCode.first));
	}
	return reversedHuffmanCodes;
}

bool Util::IsCompressing(std::string fileString, std::string compressedExtension)
{
    bool compressing = true;
    std::size_t found = fileString.find(compressedExtension);

    if (found != std::string::npos) {
        compressing = false;
    }
    return compressing;
}
