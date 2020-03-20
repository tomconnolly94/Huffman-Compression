#include "Util.h"

int Util::ConvertBinaryToDecimal(std::string strInput)
{
	long long input = std::stoll(strInput);

	int decimalNumber = 0, i = 0, remainder;
	while (input != 0)
	{
		remainder = input % 10;
		input /= 10;
		decimalNumber += remainder * (int)pow(2, i);
		++i;
	}
	return decimalNumber;
}