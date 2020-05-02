
#include "BitStreamEditor.h"
#include "HuffmanUtil.h"
#include <iostream>

std::string BitStreamEditor::ApplyHuffmanCodes(std::string inputBitStream, std::unordered_map<int, std::string> huffmanCodes)
{
    std::string output = "";

    for (unsigned i = 0; i < inputBitStream.size(); i += 8)
    {
        output += huffmanCodes[HuffmanUtil::ConvertBinaryToDecimal(inputBitStream.substr(i, 8))];
    }

    return output;
}

std::string BitStreamEditor::ReverseHuffmanCodes(std::string compressedBitStream, std::unordered_map<std::string, int> reversedHuffmanCodes)
{
    std::string output = "";
    std::string possibleKey = "";

    for (unsigned index = 0; index < compressedBitStream.size(); ++index)
    {
        possibleKey += compressedBitStream.substr(index, 1);

        if (reversedHuffmanCodes.find(possibleKey) == reversedHuffmanCodes.end()) {
            continue;
        }
        else {
            output += HuffmanUtil::ConvertDecimalToBinary(reversedHuffmanCodes[possibleKey], 8);
            possibleKey = "";
        }
    }

    return output;
}
