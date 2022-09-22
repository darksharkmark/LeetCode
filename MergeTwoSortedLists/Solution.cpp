#include "Solution.h"
#include <iostream>

ListNode* Solution::mergeTwoLists(ListNode* list1, ListNode* list2)
{
	ListNode* mergedHead { nullptr };
	ListNode* mergedNext { nullptr };
	ListNode* next1 { nullptr };
	ListNode* next2 { nullptr };

	ListNode* printNode{ nullptr };

	next1 = list1;
	next2 = list2;
	while (next1 != nullptr || next2 != nullptr)
	{
		if ((next1 != nullptr) && (next2 == nullptr))
		{
			// increment list 1 node
			if (mergedHead == nullptr)
			{
				// if we are at the start, set the head node
				mergedHead = new ListNode(next1->val);

				// then set the head's next to our merged next
				mergedNext = mergedHead->next;
			}
			else
			{
				if (mergedNext == nullptr)
				{
					mergedHead->next = new ListNode(next1->val);
					mergedNext = mergedHead->next;

				}
				else // if we already have a valid head, set the next node
				{
					mergedNext->next = new ListNode(next1->val);
					mergedNext = mergedNext->next;
				}
			}

			next1 = next1->next;

			continue;
		}

		if ((next2 != nullptr) && (next1 == nullptr))
		{
			// increment list 1 node
			if (mergedHead == nullptr)
			{
				// if we are at the start, set the head node
				mergedHead = new ListNode(next2->val);

				// then set the head's next to our merged next
				mergedNext = mergedHead->next;
			}
			else
			{
				if (mergedNext == nullptr)
				{
					mergedHead->next = new ListNode(next2->val);
					mergedNext = mergedHead->next;
				}
				else // if we already have a valid head, set the next node
				{
					mergedNext->next = new ListNode(next2->val);
					mergedNext = mergedNext->next;
				}
			}

			next2 = next2->next;

			continue;
		}
		
		// check to see which value is lower, that is the next value
		if (next1->val < next2->val)
		{
			// increment list 1 node
			if (mergedHead == nullptr)
			{
				// if we are at the start, set the head node
				mergedHead = new ListNode(next1->val);

				// then set the head's next to our merged next
				mergedNext = mergedHead->next;
			}
			else
			{
				if (mergedNext == nullptr)
				{
					mergedHead->next = new ListNode(next1->val);
					mergedNext = mergedHead->next;
				}
				else
				{
					mergedNext->next = new ListNode(next1->val);
					mergedNext = mergedNext->next;
				}
			}

			// finally, increment the list one node as we have saved tha value
			next1 = next1->next;
		}
		else if (next2->val < next1->val)
		{
			// increment list 2 node
			if (mergedHead == nullptr)
			{
				// if we are at the start, set the head node
				mergedHead = new ListNode(next2->val);

				// then set the head's next to our merged next
				mergedNext = mergedHead->next;
			}
			else
			{
				if (mergedNext == nullptr)
				{
					mergedHead->next = new ListNode(next2->val);
					mergedNext = mergedHead->next;
				}
				else
				{
					// if we already have a valid head, set the next node
					mergedNext->next = new ListNode(next2->val);
					mergedNext = mergedNext->next;
				}
			}

			// finally, increment the list one node as we have saved the value
			next2 = next2->next;
		}
		else if (next1->val == next2->val) // finally, if both values are the same increment both nodes
		{
			if (mergedHead == nullptr)
			{
				// if we are at the start, set the head node to list1
				mergedHead = new ListNode(next1->val);

				// and set the next node to list 2 (order doesnt matter here)
				mergedHead->next = new ListNode(next2->val);

				mergedNext = mergedHead->next;
			}
			else
			{
				if (mergedNext == nullptr)
				{
					mergedHead->next = new ListNode(next1->val);
					mergedHead->next->next = new ListNode(next2->val);
					mergedNext = mergedHead->next->next;
				}
				else
				{
					mergedNext->next = new ListNode(next1->val);
					mergedNext->next->next = new ListNode(next2->val);
					mergedNext = mergedNext->next->next;
				}
			}

			next1 = next1->next;
			next2 = next2->next;
		}
		else
		{
			next1 = nullptr;
			next2 = nullptr;
		}
	}

	next1 = nullptr;
	next2 = nullptr;

	printNode = mergedHead;

	std::cout << "printing nodes: " << std::endl;

	while (printNode != nullptr)
	{
		std::cout << printNode->val << ", ";
		printNode = printNode->next;
	}

	std::cout << std::endl;
	printNode = nullptr;
	return mergedHead;
}
