#pragma once

#include <map>
#include <unordered_set>


namespace LinkedListCycle {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
 
    namespace Map {
        class Solution {
        public:
            bool hasCycle(ListNode* head) {
                std::map<ListNode*, int> visited;

                while (head) {
                    if (visited.find(head) != visited.end()) {
                        return true;
                    }
                    else {
                        visited[head]++;
                    }
                    head = head->next;
                }

                return false;
            }
        };
    }

    namespace UnorderSet {
        class Solution {
        public:
            bool hasCycle(ListNode* head) {
                std::unordered_set<ListNode*> visited;

                while (head) {
                    if (visited.find(head) != visited.end()) {
                        return true;
                    }
                    else {
                        visited.insert(head);
                    }
                    head = head->next;
                }

                return false;

            }
        };
    }

    namespace FloydCycleFinding {
        class Solution {
        public:
            bool hasCycle(ListNode* head) {
                ListNode* slow = head;
                ListNode* fast = head;

                while (fast && fast->next) {
                    slow = slow->next;
                    fast = fast->next->next;

                    if (slow == fast) {
                        return true;
                    }
                }

                return false;

            }
        };
    }
    
}