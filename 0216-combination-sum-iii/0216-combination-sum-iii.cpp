class Solution {
public:

    void backtrack(int k, int n, vector<vector<int>>& ans, vector<int> &temp, int idx){
        if(n == 0 && temp.size() == k){
            ans.push_back(temp);
            return;
        }
        if(n < 0){
            return;
        }
        if(idx > 9){
            return;
        }
        if(temp.size() >= k){
            return;
        }

        temp.push_back(idx);
        backtrack(k, n-idx, ans, temp, idx + 1);

        temp.pop_back();
        backtrack(k, n, ans, temp, idx+1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        int idx =1;
        backtrack(k,n,ans,temp,idx);
        return ans;
    }
};