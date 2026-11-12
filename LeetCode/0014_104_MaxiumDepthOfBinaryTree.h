#pragma once


namespace MaximumDepthOfBinaryTree {
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
        int max(int a, int b) {
            return a >= b ? a : b;
        }

        int maxBranch(TreeNode* p) {

            if (p == nullptr) return 0;
            
            return 1 + max(maxBranch(p->left), maxBranch(p->right));
        }

        int maxDepth(TreeNode* root) {
            return maxBranch(root);
        }
    };
}