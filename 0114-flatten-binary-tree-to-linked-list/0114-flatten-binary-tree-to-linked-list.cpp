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

    void preOrder(TreeNode* node, vector<TreeNode*> &trav){
        if(node == nullptr){
            return;
        }
        trav.push_back(node);
        preOrder(node->left, trav);
        preOrder(node->right, trav);
    }

    void flatten(TreeNode* root) {
        vector<TreeNode*> trav;
        preOrder(root, trav);

        TreeNode* newRoot = nullptr;

        for(auto &it : trav){
            if(it == root){
                newRoot = root;
            }
            else{
                newRoot->right = it;
                newRoot = newRoot->right;
            }
            newRoot->left = nullptr;

        }
        
    }
};