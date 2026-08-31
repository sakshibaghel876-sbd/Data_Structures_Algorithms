/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool mirror(TreeNode* p, TreeNode* q) {

        // Both are NULL
        if (p == nullptr && q == nullptr) {
            return true;
        }

        // One is NULL
        if (p == nullptr || q == nullptr) {
            return false;
        }

        // Values are different
        if (p->val != q->val) {
            return false;
        }

        // Compare opposite sides
        return mirror(p->left, q->right) &&
               mirror(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {

        if (root == nullptr) {
            return true;
        }

        return mirror(root->left, root->right);
    }
};