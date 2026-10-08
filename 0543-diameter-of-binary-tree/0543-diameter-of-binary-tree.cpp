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

    int solve(TreeNode* root, int &diameter){
        if(root == nullptr)return 0;
        int right = solve(root->right, diameter);
        int left = solve(root->left, diameter);
        diameter = max(diameter, right+left);
        return 1+max(right, left);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)return 0;
        int diameter = 0;
        solve(root, diameter);
        return diameter;
    }
};