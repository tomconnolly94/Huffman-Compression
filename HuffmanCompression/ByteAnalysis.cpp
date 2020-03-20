#include "ByteAnalysis.h"
#include "Util.h"

unsigned* ByteAnalysis::CountByteFrequency(std::string input) {
    unsigned* count = new unsigned[256];

    for (int i = 0; i < 256; i++)
        count[i] = 0;

    for (int i = 0; i < input.size(); ++i)
    {
        count[Util::ConvertBinaryToDecimal(input.substr(0, 8))]++;
    }
    return count;
}
