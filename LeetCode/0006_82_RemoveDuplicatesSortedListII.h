#pragma once

#include<map>

/*
You are given the head of a sorted linked list.

Delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.

Example 1:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:
Input: head = [1,1,1,2,3]
Output: [2,3]
*/
namespace RemoveDuplicateFromSortedListII {
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

	class Solution {
	public:

		std::map<int, int> countExits(ListNode* head) {
			std::map<int, int> count;
			while (head != nullptr) {
				count[head->val]++;
				head = head->next;
			}
			return count;
		}

		ListNode* deleteDuplicates(ListNode* head) {
			ListNode* result = new ListNode();
			ListNode* resultCur = result;

			std::map<int, int> numberOfExits = countExits(head);

			for (auto it = numberOfExits.begin(); it != numberOfExits.end(); ++it) {
				if (it->second == 1) {
					ListNode* temp = new ListNode(it->first, nullptr);
					resultCur->next = temp;
					resultCur = resultCur->next;
				}
			}
		
			result = result->next;
			return result;
		}
	};
}