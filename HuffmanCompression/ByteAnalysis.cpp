
#include "ByteAnalysis.h"
#include "Util.h"
#include "HuffmanTree.h"

std::vector<HuffmanNode*> ByteAnalysis::CountByteFrequency(std::string input) {
    std::unordered_map<int, int> count;

    for (unsigned i = 0; i < input.size(); i += 8)
    {
        count[Util::ConvertBinaryToDecimal(input.substr(i, 8))]++;
    }
    
    return GetHuffmanNodes(count);
}

std::vector<HuffmanNode*> ByteAnalysis::GetHuffmanNodes(const std::unordered_map<int, int>& pairMap)
{
    std::vector<HuffmanNode*> huffmanNodes;
    for (std::pair<int, int> pair : pairMap) {
        huffmanNodes.push_back(new HuffmanNode(pair.first, pair.second));
    }
    HuffmanTree::SortHuffmanNodes(huffmanNodes);
    return huffmanNodes;
}