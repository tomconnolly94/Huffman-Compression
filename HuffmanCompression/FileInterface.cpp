
#include <fstream>
#include <bitset>

#include "FileInterface.h"


using byte = unsigned char;
const int BITS_PER_BYTE = 8;
using bitsInByte = std::bitset<BITS_PER_BYTE>;

std::string FileInterface::ReadFileAsBits(std::string file)
{

    std::string fileContent = "";
    std::ifstream fileStream(file, std::ios::binary | std::ios::in);
    char c;

    while (fileStream.get(c))
    {
        fileContent += bitsInByte(byte(c)).to_string();
    }

    return fileContent;
}

void FileInterface::WriteBitsToFile(std::string bitstring, const char* file)
{
    // pad with zeroes to make it represent an integral multiple of bytes
    while (bitstring.size() % BITS_PER_BYTE) bitstring += '0';

    std::ofstream fileStream(file, std::ios::binary); // open in binary mode

    for (std::size_t i = 0; i < bitstring.size(); i += BITS_PER_BYTE)
    {
        // convert each sequence of '0' or '1' to a byte
        byte b = bitsInByte(bitstring.substr(i, BITS_PER_BYTE)).to_ulong();
        fileStream << b; // and write it
    }
}