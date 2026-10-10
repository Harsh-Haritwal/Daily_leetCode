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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr)return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        vector<vector<long long>> indices;
        while (!q.empty()) {
            int sz = q.size();
            vector<long long> temp;
            long long base = q.front().second;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front().first;
                long long idx = q.front().second;
                
                q.pop();
                if (node->left != nullptr) {
                    q.push({node->left, (idx * 2 + 1)-base});
                }
                if (node->right != nullptr) {
                    q.push({node->right, (idx * 2 + 2)-base});
                }
                temp.push_back(idx);
            }
            indices.push_back(temp);
        }

        long long ans = 0;

        for(auto p : indices){
          ans =  max(ans, p.back() - p.front()+1);
        }
        return ans;
    }
};