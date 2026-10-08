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

    int solve(TreeNode* root){
        int left = 0;
        int right = 0;
        if(root->left != nullptr){
            left = solve(root->left);
        }
        if(root->right != nullptr){
            right = solve(root->right);
        }
        
        return 1+max(left, right);
    }

    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return solve(root);

    }
};