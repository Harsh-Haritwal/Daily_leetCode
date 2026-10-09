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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr)return {};
        queue<pair<TreeNode*, int>> q;
        map<int,int>mp;

        q.push({root,0});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int y = q.front().second;
            q.pop();
            mp[y] = node->val;

            if(node->left != nullptr){
                q.push({node->left,y+1});
            }
            if(node->right != nullptr){
                q.push({node->right,y+1});
            }
        }
        vector<int> ans;
        for(auto p : mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};