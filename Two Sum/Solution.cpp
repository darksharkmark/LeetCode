#include "Solution.h"

std::vector<int> Solution::twoSum(std::vector<int> nums, int target)
{
    if (nums.size() == 2)
    {
        return { 0, 1 };
    }

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (i != j && nums[i] + nums[j] == target)
            {
                return { i, j };
            }
        }
    }

    return{};
}
