//external includes
#include <ctime>
#include <sstream>

//internal includes
#include "CompressionAnalysis.h"

CompressionAnalysis::CompressionAnalysis()
{
	fileSizeStart = 0.0;
	fileSizeEnd = 0.0;
	time_t startTime = 0;
	time_t endTime = 0;
	compressionOperation = CompressionOperation::Unspecified;
}
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
	report["fileSizeReduction"] = fileSizeStart - fileSizeEnd;

	std::stringstream ss(startTime - endTime);
	report["timeTaken"] = ss.str();
	report["operationType"] = "";// compressionOperation.ToString("G");
	return report;
}