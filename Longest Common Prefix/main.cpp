/*
	Write a function to find the longest common prefix string amongst an array of strings.
	If there is no common prefix, return an empty string "".

	Example 1:

	Input: strs = ["flower","flow","flight"]
	Output: "fl"
	Example 2:

	Input: strs = ["dog","racecar","car"]
	Output: ""
	Explanation: There is no common prefix among the input strings.


	Constraints:

	1 <= strs.length <= 200
	0 <= strs[i].length <= 200
	strs[i] consists of only lowercase English letters.
*/

#include "Solution.h"
#include <iostream>
#include <vector>

void CheckResult(bool statement);

int main()
{
	Solution solution;

	{
		std::vector<std::string> input{ "flower","flow","flight" };
		auto result = solution.longestCommonPrefix(input);
		CheckResult(result == "fl");
	}

	{
		std::vector<std::string> input{ "dog","racecar","car" };
		auto result = solution.longestCommonPrefix(input);
		CheckResult(result == "");
	}

	{
		std::vector<std::string> input{ "flower","flow","flight", "f" };
		auto result = solution.longestCommonPrefix(input);
		CheckResult(result == "f");
	}


	{
		std::vector<std::string> input{ "a" };
		auto result = solution.longestCommonPrefix(input);
		CheckResult(result == "f");
	}

	return 0;
}

void CheckResult(bool statement)
{
	if (statement)
	{
		std::cout << "SUCCESS" << std::endl;
	}
	else
	{
		std::cout << "FAILURE" << std::endl;
	}
}