#pragma once

#include<iostream>

/*
* Given the roots of two binary trees p and q, write a function to
* check if they are the same or not.
* 
* Two binary trees are considered the same if they are structurally
* identical, and the nodes have the same value.
* 
* Example 1:
* Input: p = [1,2,3], q = [1,2,3]
* Output: true
* 
* Example 2:
* Input: p = [1,2], q = [1,null,2]
* Output: false
* 
* Example 3:
* Input: p = [1,2,1], q = [1,1,2]
* Output: false
*/
namespace SameTree {

    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };

    class Solution {
    public:

        bool isSameTree(TreeNode* p, TreeNode* q) {

            if (p == nullptr && q == nullptr) return true;
            
            if ((p == nullptr && q != nullptr)
                || (p != nullptr && q == nullptr)) {
                return false;
            }
            if ((p->val == q->val) && p->left == nullptr && p->right == nullptr
                && q->left == nullptr && q->right == nullptr) {
                return true;
            }
            else if ((p->val != q->val)) {
                return false;
            }
            

            
            
            bool isEqualLeft = isSameTree(p->left, q->left);
            bool isEqualRight = isSameTree(p->right, q->right);

            if (isEqualLeft && isEqualRight) {
                return true;
            }
            else {
                return false;
            }
        }
    };

    void testSameTree() {
        TreeNode* p = new TreeNode();
        TreeNode* q = new TreeNode();

        p->val = 1;
        p->left = new TreeNode(2, nullptr, nullptr);

        q->val = 1;
        q->right = new TreeNode(2, nullptr, nullptr);

        Solution s;
        std::cout << s.isSameTree(p, q);
    }
}