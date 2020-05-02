#pragma once
//external includes
#include <string>
#include <map>
#include <ctime>

class CompressionAnalysis {
public:
	CompressionAnalysis(const char* filePath);
	enum class CompressionOperation { Compressing, Decompressing, Unspecified };
	void ReportOperationType(CompressionOperation operation);
	void RecordFileSizeStart(double fileize);
	void RecordFileSizeEnd(double fileize);
	void RecordCompressionStartTime();
	void RecordCompressionEndTime();
	std::map<std::string, std::string> GetAnalysisReport();

private:
	CompressionOperation compressionOperation;
	double fileSizeStart;
	double fileSizeEnd;
	time_t startTime;
	time_t endTime;
};