#include "Solution.h"
#include <iostream>
#include <vector>

void CheckResult(bool statement);

int main()
{
	Solution solution;

	//{
	//	std::string input = "()";
	//	auto result = solution.isValid(input);
	//	CheckResult(result);
	//}

	{
		std::string input = "(){}[]";
		auto result = solution.isValid(input);
		CheckResult(result);
	}

	//{
	//	std::string input = "(]";
	//	auto result = solution.isValid(input);
	//	CheckResult(!result);
	//}

	{
		std::string input = "([)]";
		auto result = solution.isValid(input);
		CheckResult(!result);
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