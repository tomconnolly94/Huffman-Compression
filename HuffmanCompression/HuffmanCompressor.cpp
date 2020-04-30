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
#include "Util.h"

void HuffmanCompressor::Compress(char* filePath, std::string compressedExtension, std::string huffmanCodesFileExtension) 
{

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

    std::string serialisedHuffmanCodes = huffmanTree.SerialiseWithNewLines();

    //write serialised HuffmanTree to a new file
    std::string huffmanCodesFileName = GetNewFilePath(filePath, huffmanCodesFileExtension);
    CreateNewFile(huffmanCodesFileName);
    FileInterface::WriteStringToFile(serialisedHuffmanCodes, huffmanCodesFileName.c_str());
}

void HuffmanCompressor::Decompress(char* compressedFile, std::string compressedExtension, std::string huffmanCodesFileExtension)
{
    std::string compressedBitStream = FileInterface::ReadFileAsBits(compressedFile);
    std::string decompressedFilePath = StripExtension(std::string(compressedFile), compressedExtension);
    std::string huffmanCodesFile = GetNewFilePath(decompressedFilePath.c_str(), huffmanCodesFileExtension);

    std::unordered_map<int, std::string> huffmanCodes = HuffmanTree::DeserialiseFromNewLines(FileInterface::ReadStringFromFile(huffmanCodesFile.c_str()));
    std::unordered_map<std::string, int> reversedHuffmanCodes = Util::ReverseHuffmanCodeMap(huffmanCodes);
    
    std::string originalTextAsBits = BitStreamEditor::ReverseHuffmanCodes(compressedBitStream, reversedHuffmanCodes);

    std::string decompressedFileName = StripExtension(compressedFile, compressedExtension);

    if (!FileExists(decompressedFileName)) {
        CreateNewFile(decompressedFileName);
    }

    FileInterface::WriteBitsToFile(originalTextAsBits, decompressedFileName.c_str());
}

std::string HuffmanCompressor::GetNewFilePath(const char* filePath, std::string compressedExtension)
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

bool HuffmanCompressor::FileExists(const std::string& filePath) 
{
    struct stat buffer;
    return (stat(filePath.c_str(), &buffer) == 0);
}

std::string HuffmanCompressor::StripExtension(std::string filePath, std::string extension) 
{
    std::size_t found = filePath.find(extension);
    std::string newFilePath = filePath.substr(0, filePath.size() - extension.size());
    return newFilePath;
}