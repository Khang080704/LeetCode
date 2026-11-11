#pragma once

#include <queue>
#include <stack>

/*
* Given the root of a binary tree, check whether it is a mirror of
* itself (i.e., symmetric around its center).
* 
* Example 1:
* Input: root = [1,2,2,3,4,4,3]
* Output: true
* 
* Example 2:
* Input: root = [1,2,2,null,3,null,3]
* Output: false
* 
* Constraints:
* - The number of nodes in the tree is in the range [1, 1000]
* - -100 <= Node.val <= 100
*/
namespace SymmetricTree {

    namespace Recursive {
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
            bool isEqual(TreeNode* p, TreeNode* q) {
                if (p == nullptr && q == nullptr) return true;
                if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) return false;
                if (p->val != q->val) {
                    return false;
                }

                return isEqual(p->left, q->right) && isEqual(p->right, q->left);
            }

            bool isSymmetric(TreeNode* root) {
                return isEqual(root->left, root->right);
            }
        };
    }

    namespace Queue {
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
            bool isSymmetric(TreeNode* root) {
                std::queue<TreeNode*> treeQueue;

                treeQueue.push(root->left);
                treeQueue.push(root->right);

                while (!treeQueue.empty()) {
                    TreeNode* p = treeQueue.front();
                    treeQueue.pop();
                    TreeNode* q = treeQueue.front();
                    treeQueue.pop();

                    if (p == nullptr && q == nullptr) {
                        continue;
                    }
                    if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) return false;
                    if (p->val != q->val) {
                        return false;
                    }

                    treeQueue.push(p->left);
                    treeQueue.push(q->right);

                    treeQueue.push(p->right);
                    treeQueue.push(q->left);
                }

                return true;
            }
        };
    }

    namespace Stack {
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
            bool isSymmetric(TreeNode* root) {
                std::stack<TreeNode*> stackTree;

                stackTree.push(root->left);
                stackTree.push(root->right);

                while (!stackTree.empty()) {
                    TreeNode* p = stackTree.top();
                    stackTree.pop();
                    TreeNode* q = stackTree.top();
                    stackTree.pop();

                    if (p == nullptr && q == nullptr) {
                        continue;
                    }
                    if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) return false;
                    if (p->val != q->val) {
                        return false;
                    }

                    stackTree.push(p->left);
                    stackTree.push(q->right);

                    stackTree.push(p->right);
                    stackTree.push(q->left);
                }

                return true;
            }
        };
    }
	
}