#include "Solution.h"

#include <algorithm>

bool isShorter(const std::string& A, const std::string& B )
{
	return A.length() < B.length();
}

std::string Solution::longestCommonPrefix(std::vector<std::string>& strs)
{
	if (strs.size() == 1)
	{
		return strs.front();
	}

	std::string result = "";

	// the longers common prefix is limited by the longest entry
	if (std::is_sorted(strs.begin(), strs.end(), isShorter) == false)
	{
		std::sort(strs.begin(), strs.end(), isShorter);
	}

	const auto shortestWord = strs.front();
	strs.erase(strs.begin());
	
	bool isEqual = false;
	std::string longestCurrentPrefix;

	for (size_t i = 1; i < shortestWord.length() + 1; i++)
	{
		for (size_t j = 0; j < strs.size(); j++)
		{
			auto longestPossiblePrefix = shortestWord.substr(0, i);
			auto comparingWord = strs[j];
			longestCurrentPrefix = comparingWord.substr(0, i);

			isEqual = longestPossiblePrefix == longestCurrentPrefix;

			if (!isEqual)
			{
				break;
			}
		}

		if (!isEqual)
		{
			break;
		}
		else
		{
			result = longestCurrentPrefix;
		}
	}

	return result;
}
