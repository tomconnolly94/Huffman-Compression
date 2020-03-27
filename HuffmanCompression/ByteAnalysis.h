#pragma once
#include <string>
#include <map>

class ByteAnalysis {
public:
	static std::map<int, int> CountByteFrequency(std::string input);
};