#pragma once
//external includes
#include <string>

//internal includes
#include "CompressionAnalysis.h"

class HuffmanCompressor {
public:
	static int Compress(const char* filePath, std::string compressedExtension, std::string huffmanCodesFileExtension, CompressionAnalysis& compressionAnalysis);
	static int Decompress(const char* filePath, std::string compressedExtension, std::string huffmanCodesFileExtension, CompressionAnalysis& compressionAnalysis);
};