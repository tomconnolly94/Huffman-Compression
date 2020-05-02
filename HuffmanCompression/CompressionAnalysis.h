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
	void RecordFileSizeStart(int fileize);
	void RecordFileSizeEnd(int fileize);
	void RecordCompressionStartTime();
	void RecordCompressionEndTime();
	void PrintAnalysisReport();
private:
	std::map<std::string, std::string> GetAnalysisReport();
	CompressionOperation compressionOperation;
	int fileSizeStart;
	int fileSizeEnd;
	time_t startTime;
	time_t endTime;
	std::map<CompressionOperation, std::string> enumTranslations;
};