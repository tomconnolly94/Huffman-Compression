#include <algorithm>
#include <set>
#include <algorithm>
#include <functional>

#include "ByteAnalysis.h"
#include "Util.h"

std::unordered_map<int, int> ByteAnalysis::CountByteFrequency(std::string input) {
    std::map<int, int> count;

    for (unsigned i = 0; i < input.size(); i += 8)
    {
        count[Util::ConvertBinaryToDecimal(input.substr(i, 8))]++;
    }

    return SortByteFrequency(count);
}

std::unordered_map<int, int> ByteAnalysis::SortByteFrequency(std::map<int, int> count) {

    // Declaring the type of Predicate that accepts 2 pairs and return a bool
    typedef std::function<bool(std::pair<int, int>, std::pair<int, int>)> Comparator;

    // Defining a lambda function to compare two pairs. It will compare two pairs using second field
    Comparator compFunctor = [](std::pair<int, int> elem1, std::pair<int, int> elem2)
    {
        return elem1.second < elem2.second;
    };

    std::set<std::pair<int, int>, Comparator> setCount(count.begin(), count.end(), compFunctor);

    std::unordered_map<int, int> sortedMap;

    for (std::pair<int, int> element : setCount)
    {
        sortedMap[element.first] = element.second;
    }
    return sortedMap;
}