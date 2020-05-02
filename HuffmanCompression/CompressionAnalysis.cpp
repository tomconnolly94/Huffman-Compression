//external includes
#include <sstream>
#include <iostream>

//internal includes
#include "CompressionAnalysis.h"
#include "HuffmanUtil.h"

CompressionAnalysis::CompressionAnalysis(const char* filePath) :
	fileSizeStart(0),
	fileSizeEnd(0),
	startTime(0),
	endTime(0),
	compressionOperation(CompressionOperation::Unspecified),
	enumTranslations({ {CompressionOperation::Compressing, "Compressing"}, {CompressionOperation::Decompressing, "Decompressing"}, {CompressionOperation::Unspecified, "Unspecified"} })
{}

void CompressionAnalysis::ReportOperationType(CompressionOperation operation)
{
	compressionOperation = operation;
}

void CompressionAnalysis::RecordFileSizeStart(int fileSize)
{
	fileSizeStart = fileSize;
}

void CompressionAnalysis::RecordFileSizeEnd(int fileSize)
{
	fileSizeEnd = fileSize;
}

void CompressionAnalysis::RecordCompressionStartTime()
{
	startTime = std::clock();
}

void CompressionAnalysis::RecordCompressionEndTime()
{
	endTime = std::clock();
}

std::map<std::string, std::string> CompressionAnalysis::GetAnalysisReport()
{
	std::map<std::string, std::string> report;

	int fileSizeDifference = fileSizeEnd - fileSizeStart;
	int timeDifference = endTime - startTime;

	report["Operation Type"] = enumTranslations[compressionOperation];
	report["File Size Difference"] = std::to_string(fileSizeDifference) + " kB";
	report["Time Taken"] = std::to_string(timeDifference) + " ms";
	report["Compression Rate"] = std::to_string(abs(fileSizeDifference / timeDifference)) + " kBs/ms";
	return report;
}

void CompressionAnalysis::PrintAnalysisReport() 
{
	std::cout << "Analysis Report: " << std::endl << std::endl;
	std::map<std::string, std::string> compressionAnalysisReport = GetAnalysisReport();

	for (std::map<std::string, std::string>::iterator it = compressionAnalysisReport.begin(); it != compressionAnalysisReport.end(); it++)
	{
		std::cout << it->first << ": " << it->second << std::endl;
	}
}