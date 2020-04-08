//external includes
#include <iostream>
#include <vector>

//internal includes
#include "HuffmanCompressor.h"
#include "FileInterface.h"
#include "HuffmanNode.h"
#include "BitStreamAnalysis.h"
#include "BitStreamEditor.h"
#include "HuffmanTree.h"

void HuffmanCompressor::Compress(char* filePath) {

	std::string bitStream = FileInterface::ReadFileAsBits(filePath);
	std::vector<HuffmanNode*> huffmanNodes = BitStreamAnalysis::CountByteFrequency(bitStream);
	HuffmanTree huffmanTree(huffmanNodes);
	std::unordered_map<int, std::string> huffmanCodes = huffmanTree.GenerateHuffmanCodes();

	//replace each occurence of huffmanCode.first found in bitStream with the corresponding huffmanCode.second
	std::string outputBitStream = BitStreamEditor::ApplyHuffmanCodes(bitStream, huffmanCodes);

	//write outputBitStream to a new file

}