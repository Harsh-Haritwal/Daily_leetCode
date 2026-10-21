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

    int dfs(TreeNode* node, int &camera){
        if(node->left == nullptr && node->right == nullptr)return 2;
        int lt = 0;
        int rt = 0;
        if(node->left != nullptr){
            lt = dfs(node->left,camera);
        }
        if(node->right != nullptr){
            rt = dfs(node->right,camera);
        }

        if(lt == 2 || rt == 2){
            camera++;
            return 1;
        }
        if(lt == 1 || rt == 1){
            return 0;
        }
        return 2
        ;
    }

    int minCameraCover(TreeNode* root) {
        int camera = 0;
        int val = dfs(root, camera);
        if(val == 2)camera++;
        return camera;
    }
};