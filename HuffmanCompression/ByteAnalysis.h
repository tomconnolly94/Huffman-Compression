#pragma once
#include <string>
#include <unordered_map>
#include <map>
#include <vector>

class ByteAnalysis {
public:
	static std::unordered_map<int, int> CountByteFrequency(std::string input);
private:
	static std::unordered_map<int, int> SortByteFrequency(std::map<int, int> count);
};