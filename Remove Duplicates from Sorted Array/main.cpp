
#include "Solution.h"

#include <iostream>

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

int main()
{
	Solution solution;

	{
		std::vector<int> vec_input{ 0,0,1,1,1,2,2,3,3,4 };
		std::vector<int> vec_output{ 0,1,2,3,4 };

		int output = 5;
		int result = solution.removeDuplicates(vec_input);

		CheckResult(result == output);
		CheckResult(vec_input == vec_output);
	}

	return 0;
}
