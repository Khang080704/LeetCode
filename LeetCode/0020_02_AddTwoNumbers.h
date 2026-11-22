#pragma once

#include <iostream>
#include <math.h>

/*
* You are given two non-empty linked lists representing two non-negative
* integers. The digits are stored in reverse order, and each of their nodes
* contains a single digit. Add the two numbers and return the sum as a linked
* list.
* 
* You may assume the two numbers do not contain any leading zero, except the
* number 0 itself.
* 
* Example 1:
* Input: l1 = [2,4,3], l2 = [5,6,4]
* Output: [7,0,8]
* Explanation: 342 + 465 = 807.
* 
* Example 2:
* Input: l1 = [0], l2 = [0]
* Output: [0]
* 
* Example 3:
* Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
* Output: [8,9,9,9,0,0,0,1]
*/
namespace AddTwoNumbers {

    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };


    class Solution {
    public:

        int length(ListNode* list) {
            int count = 0;
            while (list) {
                count++;
                list = list->next;
            }
            return count;
        }

        void addNode(ListNode*& head, int num) {
            ListNode* cur = head;

            while (cur->next != nullptr) {
                cur = cur->next;
            }

            for (int i = 1; i <= num; i++) {
                ListNode* temp = new ListNode();
                cur->next = temp;
                cur = cur->next;
            }
        }

        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int num = abs(length(l1) - length(l2));
            if (length(l1) > length(l2)) {
                addNode(l2, num);
            }
            else if (length(l1) < length(l2)) {
                addNode(l1, num);
            }

            bool carry = false;

            ListNode* result = new ListNode();
            ListNode* cur = result;

            while (l1) {
                int value = l1->val + l2->val;

                if (l1->next == nullptr) {
                    if (carry) {
                        value++;
                    }

                    if (value >= 10) {
                        ListNode* first = new ListNode(value % 10);
                        ListNode* second = new ListNode(value / 10);
                        first->next = second;
                        cur->next = first;
                    }
                    else {
                        ListNode* first = new ListNode(value);
                        cur->next = first;
                    }
                    break;
                }


                if (carry) {
                    value++;
                    if (value >= 10) {
                        carry = true;
                        ListNode* temp = new ListNode(value % 10);
                        cur->next = temp;
                    }
                    else {
                        ListNode* temp = new ListNode(value);
                        cur->next = temp;
                        carry = false;
                    }
                    cur = cur->next;
                }
                else {
                    if (value >= 10) {
                        carry = true;
                        ListNode* temp = new ListNode(value % 10);
                        cur->next = temp;
                    }
                    else {
                        ListNode* temp = new ListNode(value);
                        cur->next = temp;
                    }
                    cur = cur->next;
                }

                l1 = l1->next;
                l2 = l2->next;
            }
            
            result = result->next;
            return result;

        }
            
    };

    void testAddTwoNumbers() {
        ListNode* a = new ListNode(10);
        Solution s;
        s.addNode(a, 4);

        while (a) {
            std::cout << a->val << " ";
            a = a->next;
        }
    }
}