/*
	Remove duplicates inplace
	do not allocate extra memory

	modify input to have new result
	return new size
*/

#include "Solution.h"

#include <algorithm>
#include <functional>

int Solution::removeDuplicates(std::vector<int>& nums)
{
	// sanity check to see if already unique
	int result = nums.size();
	int num_elements_removed { 0 };
	auto duplicatePosition = std::adjacent_find(nums.begin(), nums.end(), std::equal_to<int>() );

	while (duplicatePosition != nums.end())
	{
		nums.erase(duplicatePosition);
		++num_elements_removed;

		duplicatePosition = std::adjacent_find(nums.begin(), nums.end(), std::equal_to<int>());
	} 

	return result - num_elements_removed;
}
