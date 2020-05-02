//internal includes
#include "BitStreamAnalysis.h"
#include "HuffmanUtil.h"
#include "HuffmanTree.h"

std::vector<HuffmanNode*> BitStreamAnalysis::CountByteFrequency(std::string input) {
    std::unordered_map<int, int> count;

    for (unsigned i = 0; i < input.size(); i += 8)
    {
        count[HuffmanUtil::ConvertBinaryToDecimal(input.substr(i, 8))]++;
    }
    
    return GetHuffmanNodes(count);
}

std::vector<HuffmanNode*> BitStreamAnalysis::GetHuffmanNodes(const std::unordered_map<int, int>& pairMap)
{
    std::vector<HuffmanNode*> huffmanNodes;
    for (std::pair<int, int> pair : pairMap) {
        huffmanNodes.push_back(new HuffmanNode(pair.first, pair.second));
    }
    HuffmanTree::SortHuffmanNodes(huffmanNodes);
    return huffmanNodes;
}