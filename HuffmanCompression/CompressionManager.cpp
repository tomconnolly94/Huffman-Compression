//external includes
#include <iostream>

//internal includes
#include "CompressionManager.h"
#include "HuffmanCompressor.h"
#include "HuffmanUtil.h"
#include "HuffmanFileInterface.h"
#include "CompressionAnalysis.h"

CompressionManager::CompressionManager(const char* filePath) : filePath(filePath), compressionAnalysis(filePath), compressionOperation(CompressionAnalysis::CompressionOperation::Unspecified), operationSuccess(0){}

int CompressionManager::Run()
{
    //ensure filePath exists
    if (!HuffmanFileInterface::FileExists(filePath))
    {
        std::cout << "ERROR: Input file does not exist! Please provide the software with a file that exists on disk." << std::endl;
        return 1;
    }

    if (HuffmanUtil::IsCompressing(filePath, compressedExtension))
    {
        compressionOperation = CompressionAnalysis::CompressionOperation::Compressing;
    }
    else
    {
        compressionOperation = CompressionAnalysis::CompressionOperation::Decompressing;
    }

    compressionAnalysis.ReportOperationType(compressionOperation);
    compressionAnalysis.RecordCompressionStartTime();

    if (compressionOperation == CompressionAnalysis::CompressionOperation::Compressing)
    {
        operationSuccess = HuffmanCompressor::Compress(filePath, compressedExtension, huffmanCodesFileExtension);
    }
    else
    {
        operationSuccess = HuffmanCompressor::Decompress(filePath, compressedExtension, huffmanCodesFileExtension);
    }
    compressionAnalysis.RecordCompressionEndTime();

    std::map<std::string, std::string> compressionAnalysisReport = compressionAnalysis.GetAnalysisReport();

    //print analysis report
    for (std::map<std::string, std::string>::iterator it = compressionAnalysisReport.begin(); it != compressionAnalysisReport.end(); it++)
    {
        std::cout << it->first  // string (key)
            << ': '
            << it->second   // string's value 
            << std::endl;
    }

    return operationSuccess;
}