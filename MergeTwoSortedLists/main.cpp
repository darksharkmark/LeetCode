/*
* The number of nodes in both lists is in the range [0, 50].
* -100 <= Node.val <= 100
* Both list1 and list2 are sorted in non-decreasing order.
*/

#include "Solution.h"
#include <iostream>

void CheckResult(bool statement);

int main()
{
	Solution solution;
	{
		ListNode* listA_1 = new ListNode(1);
		ListNode* listA_2 = new ListNode(2);
		ListNode* listA_3 = new ListNode(4);

		listA_1->next = listA_2;
		listA_2->next = listA_3;

		ListNode* listB_1 = new ListNode(1);
		ListNode* listB_2 = new ListNode(3);
		ListNode* listB_3 = new ListNode(4);

		listB_1->next = listB_2;
		listB_2->next = listB_3;

		solution.mergeTwoLists(listA_1, listB_1);
	}
	
	{
		ListNode* listA_1 = nullptr;
		ListNode* listB_1 = new ListNode(0);
	
		solution.mergeTwoLists(listA_1, listB_1);
	}

	{
		ListNode* listA_1 = new ListNode(2);
		ListNode* listB_1 = new ListNode(1);

		solution.mergeTwoLists(listA_1, listB_1);
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