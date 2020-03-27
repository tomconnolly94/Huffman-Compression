#include "ByteAnalysis.h"
#include "Util.h"

std::map<int, int> ByteAnalysis::CountByteFrequency(std::string input) {
    //unsigned* count = new unsigned[256];
    std::map<int, int> count;

    for (int i = 0; i < 256; i++)
        count[i] = 0;

    for (int i = 0; i < input.size(); i += 8)
    {
        count[Util::ConvertBinaryToDecimal(input.substr(i, 8))]++;
    }
    return count;
}
