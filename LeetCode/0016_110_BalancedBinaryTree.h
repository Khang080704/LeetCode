#pragma once

#include "0011_100_SameTree.h"
#include <math.h>

namespace BalancedBinaryTree {
	using SameTree::TreeNode;

    class Solution {
    public:
        int max(int a, int b) {
            return a >= b ? a : b;
        }

        int maxBranch(TreeNode* p) {

            if (p == nullptr) return 0;

            return 1 + max(maxBranch(p->left), maxBranch(p->right));
        }

        bool isBalanced(TreeNode* root) {
            if (root == nullptr) return true;
            if (root->left == nullptr && root->right == nullptr) return true;

            if (abs(maxBranch(root->left) - maxBranch(root->right)) > 1) {
                return false;
            }

            return isBalanced(root->left) && isBalanced(root->right);
        }
    };
}