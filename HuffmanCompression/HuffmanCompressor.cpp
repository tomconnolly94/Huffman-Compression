//external includes
#include <iostream>
#include <vector>

//internal includes
#include "HuffmanCompressor.h"
#include "HuffmanFileInterface.h"
#include "HuffmanNode.h"
#include "BitStreamAnalysis.h"
#include "BitStreamEditor.h"
#include "HuffmanTree.h"
#include "HuffmanUtil.h"

int HuffmanCompressor::Compress(char* filePath, std::string compressedExtension, std::string huffmanCodesFileExtension) 
{
	std::string bitStream = HuffmanFileInterface::ReadFileAsBits(filePath);
	std::vector<HuffmanNode*> huffmanNodes = BitStreamAnalysis::CountByteFrequency(bitStream);
	HuffmanTree huffmanTree(huffmanNodes);
	std::unordered_map<int, std::string> huffmanCodes = huffmanTree.GenerateHuffmanCodes();

	//replace each occurence of huffmanCode.first found in bitStream with the corresponding huffmanCode.second
	std::string outputBitStream = BitStreamEditor::ApplyHuffmanCodes(bitStream, huffmanCodes);

    //write outputBitStream to a new file
    std::string compressedFileName = HuffmanFileInterface::GetNewFilePath(filePath, compressedExtension);
    HuffmanFileInterface::CreateNewFile(compressedFileName);
    HuffmanFileInterface::WriteBitsToFile(outputBitStream, compressedFileName.c_str());

    std::string serialisedHuffmanCodes = huffmanTree.SerialiseWithNewLines();

    //write serialised HuffmanTree to a new file
    std::string huffmanCodesFileName = HuffmanFileInterface::GetNewFilePath(filePath, huffmanCodesFileExtension);
    HuffmanFileInterface::CreateNewFile(huffmanCodesFileName);
    HuffmanFileInterface::WriteStringToFile(serialisedHuffmanCodes, huffmanCodesFileName.c_str());
    
    return 0;
}

int HuffmanCompressor::Decompress(char* compressedFile, std::string compressedExtension, std::string huffmanCodesFileExtension)
{
    std::string compressedBitStream = HuffmanFileInterface::ReadFileAsBits(compressedFile);
    std::string decompressedFilePath = HuffmanFileInterface::StripExtension(std::string(compressedFile), compressedExtension);
    std::string huffmanCodesFile = HuffmanFileInterface::GetNewFilePath(decompressedFilePath.c_str(), huffmanCodesFileExtension);

    //ensure huffmanCodesFile exists
    if (!HuffmanFileInterface::FileExists(huffmanCodesFile))
    {
        std::cout << "ERROR: the Huffman Codes file does not exist or is not located in the corrct (immediately beside compressed file) directory! Please ensure that this file (same as the input file with a '.huffCodes' extension) exists on disk." << std::endl;
        return 2;
    }

    std::unordered_map<int, std::string> huffmanCodes = HuffmanTree::DeserialiseFromNewLines(HuffmanFileInterface::ReadStringFromFile(huffmanCodesFile.c_str()));
    std::unordered_map<std::string, int> reversedHuffmanCodes = HuffmanUtil::ReverseHuffmanCodeMap(huffmanCodes);
    
    std::string originalTextAsBits = BitStreamEditor::ReverseHuffmanCodes(compressedBitStream, reversedHuffmanCodes);

    std::string decompressedFileName = HuffmanFileInterface::StripExtension(compressedFile, compressedExtension);

    if (!HuffmanFileInterface::FileExists(decompressedFileName)) {
        HuffmanFileInterface::CreateNewFile(decompressedFileName);
    }

    HuffmanFileInterface::WriteBitsToFile(originalTextAsBits, decompressedFileName.c_str());
    return 0;
}