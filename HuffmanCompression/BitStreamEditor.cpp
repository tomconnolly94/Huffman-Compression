
#include "BitStreamEditor.h"
#include "Util.h"
#include <iostream>

std::string BitStreamEditor::ApplyHuffmanCodes(std::string inputBitStream, std::unordered_map<int, std::string> huffmanCodes)
{
    std::string output = "";

    for (unsigned i = 0; i < inputBitStream.size(); i += 8)
    {
        output += huffmanCodes[Util::ConvertBinaryToDecimal(inputBitStream.substr(i, 8))];
    }

	return output;
}
