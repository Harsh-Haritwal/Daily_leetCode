/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = solve(root->left);
        int right = solve(root->right);

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr)return true;
        TreeNode* leftN = root->left;
        TreeNode* rightN = root->right;
        if (abs(solve(leftN) - solve(root->right)) > 1) {
            return false;
        }
        if(!isBalanced(leftN)){
            return false;
        }
        if(!isBalanced(rightN)){
            return false;
        }
        return true;
    }
};