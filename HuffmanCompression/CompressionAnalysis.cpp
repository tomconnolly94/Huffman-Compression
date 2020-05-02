//external includes
#include <sstream>

//internal includes
#include "CompressionAnalysis.h"
#include "HuffmanUtil.h"

CompressionAnalysis::CompressionAnalysis(const char* filePath) : 
	fileSizeStart(HuffmanUtil::GetFileSize(filePath)), 
	fileSizeEnd(0.0), 
	startTime(0), 
	endTime(0), 
	compressionOperation(CompressionOperation::Unspecified) 
{}

void CompressionAnalysis::ReportOperationType(CompressionOperation operation)
{
	compressionOperation = operation;
}

void CompressionAnalysis::RecordFileSizeStart(double fileSize)
{
	fileSizeStart = fileSize;
}

void CompressionAnalysis::RecordFileSizeEnd(double fileSize)
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

	std::ostringstream fileSizeDifference(fileSizeStart - fileSizeEnd);
	report["fileSizeReduction"] = fileSizeDifference.str();

	std::stringstream ss(startTime - endTime);
	report["timeTaken"] = ss.str();

	report["operationType"] = "";// compressionOperation.ToString("G");
	return report;
}