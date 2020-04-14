//external includes
#include <iostream>
#include <fstream>

//internal includes
#include "HuffmanFileInterface.h"

std::unordered_map<int, std::string> HuffmanFileInterface::ParseJsonToHuffmanCodes(std::string input)
{
    std::unordered_map<int, std::string> huffmanCodes;

    Json::Value jsonData;
    Json::CharReaderBuilder builder;
    std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
    std::string formattedErrors;
    const char* cinput = input.c_str();

    bool parsingSuccessful = reader->parse(cinput, cinput + strlen(cinput), &jsonData, &formattedErrors);

    if (parsingSuccessful)
    {
        /*for (std::size_t i = 0; i < jsonData.size(); ++i)
        {
            std::string tmpOut = jsonData[i].asCString();
        }*/
        std::string output = PrintJSONTree(jsonData);
    }

    return huffmanCodes;
}


std::string HuffmanFileInterface::PrintJSONValue(const Json::Value& val)
{
    std::string output = "";
    if (val.isString()) {
        output +="string(%s)", val.asString().c_str();
    }
    else if (val.isBool()) {
        output +="bool(%d)", val.asBool();
    }
    else if (val.isInt()) {
        output +="int(%d)", val.asInt();
    }
    else if (val.isUInt()) {
        output +="uint(%u)", val.asUInt();
    }
    else if (val.isDouble()) {
        output +="double(%f)", val.asDouble();
    }
    else
    {
        output +="unknown type=[%d]", val.type();
    }
    return output;
}

std::string HuffmanFileInterface::PrintJSONTree(const Json::Value& root, unsigned short depth /* = 0 */)
{
    depth += 1;
    std::string output = "";
    output += " {type=[%d], size=%d}", root.type(), root.size();

    if (root.size() > 0) {
        output += "\n";
        for (Json::Value::const_iterator itr = root.begin(); itr != root.end(); itr++) {
            // Print depth. 
            for (int tab = 0; tab < depth; tab++) {
                output += "-";
            }
            output += " subvalue(";
            output += PrintJSONValue(itr.key());
            output += ") -";
            output += PrintJSONTree(*itr, depth);
        }
        return output;
    }
    else {
        output += " ";
        output += PrintJSONValue(root);
        output += "\n";
    }
    return output;
}