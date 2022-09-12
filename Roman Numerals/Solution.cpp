/*

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

*/

#include "Solution.h"
#include <vector>
#include <iostream>

int CharToInt(const char& c)
{
	int result = -1;
	switch (c)
	{
		case 'I':
		{
			result = 1;
			break;
		}
		case 'V':
		{
			result = 5;
			break;
		}
		case 'X':
		{
			result = 10;
			break;
		}
		case 'L':
		{
			result = 50;
			break;
		}
		case 'C':
		{
			result = 100;
			break;
		}
		case 'D':
		{
			result = 500;
			break;
		}
		case 'M':
		{
			result = 1000;
			break;
		}
	default:
		break;
	}

	return result;
}

int Solution::romanToInt(std::string s)
{
	int result = 0;
	const auto stringLength = s.length();

	for (size_t i = 0; i < stringLength; i++)
	{
		if (i < stringLength - 1)
		{
			int current = CharToInt(s[i]);
			int next = CharToInt(s[i + 1]);

			bool doSubract = (current == 1 &&	(next == 5 || next == 10)) ||
							 (current == 10 &&	(next == 50 || next == 100)) ||
							 (current == 100 &&	(next == 500 || next == 1000));

			result += doSubract ? next - current : current;

			if (doSubract)
			{
				i++;
			}
		}
		else
		{
			result += CharToInt(s[i]);
		}
	}

	return result;
}

