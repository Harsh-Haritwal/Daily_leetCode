/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (root == nullptr || target == nullptr) {
            return {};
        }
        queue<TreeNode*> q;
        unordered_map<TreeNode*, TreeNode*> mp;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left != nullptr) {
                q.push(node->left);
                mp[node->left] = node;
            }
            if (node->right != nullptr) {
                q.push(node->right);
                mp[node->right] = node;
            }
        }

        queue<TreeNode*> que;
        que.push(target);

        unordered_set<TreeNode*> visited;
        visited.insert(target);

        int dist = 0;
        while (!que.empty() && dist < k) {
            int sz = que.size();

            for (int i = 0; i < sz; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (mp.find(node) != mp.end() &&
                    visited.find(mp[node]) == visited.end()) {
                    que.push(mp[node]);
                    visited.insert(mp[node]);
                }
                if (node->left != nullptr &&
                    visited.find(node->left) == visited.end()) {
                    que.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right != nullptr &&
                    visited.find(node->right) == visited.end()) {
                    que.push(node->right);
                    visited.insert(node->right);
                }
            }
            dist++;
        }
        vector<int> ans;
        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            ans.push_back(node->val);
        }

        return ans;
    }
};