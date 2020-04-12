//external includes
#include <iostream>
#include <fstream>
#include <vector>

//internal includes
#include "HuffmanCompressor.h"
#include "FileInterface.h"
#include "HuffmanNode.h"
#include "BitStreamAnalysis.h"
#include "BitStreamEditor.h"
#include "HuffmanTree.h"

void HuffmanCompressor::Compress(char* filePath, std::string compressedExtension, std::string huffmanTreeJSONExtension) {

	std::string bitStream = FileInterface::ReadFileAsBits(filePath);
	std::vector<HuffmanNode*> huffmanNodes = BitStreamAnalysis::CountByteFrequency(bitStream);
	HuffmanTree huffmanTree(huffmanNodes);
	std::unordered_map<int, std::string> huffmanCodes = huffmanTree.GenerateHuffmanCodes();

	//replace each occurence of huffmanCode.first found in bitStream with the corresponding huffmanCode.second
	std::string outputBitStream = BitStreamEditor::ApplyHuffmanCodes(bitStream, huffmanCodes);

    //write outputBitStream to a new file
    std::string compressedFileName = GetNewFilePath(filePath, compressedExtension);
    CreateNewFile(compressedFileName);
	FileInterface::WriteBitsToFile(outputBitStream, compressedFileName.c_str());

    std::string serialisedHuffmanTrees = huffmanTree.SerialiseToJSON();

    //write serialised HuffmanTree to a new file
    std::string huffmanTreeJSONFileName = GetNewFilePath(filePath, huffmanTreeJSONExtension);
    CreateNewFile(huffmanTreeJSONFileName);
    FileInterface::WriteStringToFile(serialisedHuffmanTrees, huffmanTreeJSONFileName.c_str());
}

std::string HuffmanCompressor::GetNewFilePath(char* filePath, std::string compressedExtension)
{
    std::string newFileName;
    std::string fileString(filePath);

    if (IsCompressing(filePath, compressedExtension)) {
        newFileName = fileString + compressedExtension;
    }
    else {
        newFileName = fileString.substr(0, fileString.size() - compressedExtension.size());
    }

    char* cnewFileName = &newFileName[0];
    return cnewFileName;
}

bool HuffmanCompressor::IsCompressing(std::string fileString, std::string compressedExtension)
{
    bool compressing = true;
    std::size_t found = fileString.find(compressedExtension);

    if (found != std::string::npos) {
        compressing = false;
    }
    return compressing;
}

void HuffmanCompressor::CreateNewFile(std::string filePath)
{
    std::ofstream outfile(filePath);
    outfile.close();
}