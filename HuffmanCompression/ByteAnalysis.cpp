#include <map>
#include <algorithm>

#include "ByteAnalysis.h"
#include "Util.h"

std::vector<std::pair<int, int>> ByteAnalysis::CountByteFrequency(std::string input) {
    //unsigned* count = new unsigned[256];
    std::map<int, int> count;

    for (int i = 0; i < input.size(); i += 8)
    {
        count[Util::ConvertBinaryToDecimal(input.substr(i, 8))]++;
    }


	// create an empty vector of pairs
	std::vector<std::pair<int, int>> vec;

	// copy key-value pairs from the map to the vector
	std::copy(count.begin(),
		count.end(),
		std::back_inserter<std::vector<std::pair<int, int>>>(vec));

	// sort the vector by increasing order of its pair's second value
	// if second value are equal, order by the pair's first value
	std::sort(vec.begin(), vec.end(),
		[](const std::pair<int, int>& l, const std::pair<int, int>& r) {
			if (l.second != r.second)
				return l.second < r.second;

			return l.first < r.first;
		});

    return vec;
}
