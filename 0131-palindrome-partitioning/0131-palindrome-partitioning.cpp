class Solution {
public:

    bool isPalindrome(string s, int end, int start){
        while(start <= end){
            if(s[start] == s[end]){
                start++;
                end--;
            }else{
                return false;
            }
        }
        return true;
    }

    void backtrack(string s, vector<string> &temp, vector<vector<string>> &ans, int idx){
        
        if(idx == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = idx; i<s.size();i++){
            if(isPalindrome(s,i, idx )){
                temp.push_back(s.substr(idx, i-idx+1));
                backtrack(s, temp, ans, i+1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        int idx = 0;
        backtrack(s, temp, ans,idx);
        return ans;
    }
};