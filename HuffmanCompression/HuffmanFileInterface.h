#pragma once
//external includes
#include <string>
#include <unordered_map>
#include "json/json.h"

//internal includes
#include "FileInterface.h"

class HuffmanFileInterface : public FileInterface {
public:
	static std::unordered_map<int, std::string> ParseJsonToHuffmanCodes(std::string input);
	static std::string PrintJSONTree(const Json::Value& root, unsigned short depth = 0 );
private:
	static std::string PrintJSONValue(const Json::Value& val);
};