class Solution {
public:

    bool isPalindrome(string s, int i, int j, vector<vector<int>>& dp){
        if(i>=j) return true;
        if(s[i] != s[j]) return  false;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = isPalindrome(s, i+1, j-1, dp);
    }

    int countSubstrings(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        int count = 0;
        for(int i = 0; i< s.size();i++){
            for(int j = i; j< s.size();j++){
                if(isPalindrome(s, i , j, dp)){
                    count++;
                }
            }
        }
        return count;
    }
};