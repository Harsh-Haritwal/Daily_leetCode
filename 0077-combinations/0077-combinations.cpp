class Solution {
public:

    void com(int n, int k, vector<int> &temp, vector<vector<int>> & ans, int idx){
        if ( temp.size() == k){
            ans.push_back(temp);
            return ;

        }
        if(idx > n){
            return ;
        }
        if(n - idx + 1 < k - temp.size()){
            return ;
        }
        temp.push_back(idx);
        com(n, k , temp, ans, idx + 1);
        
        temp.pop_back();

        com(n, k, temp, ans, idx + 1);
        
        
        return;
    }


    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;
        int idx = 1;
        com(n , k , temp, ans, idx);
        return ans;
    }
};