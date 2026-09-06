class Solution {
public:

    void backtrack(string digits, int idx, string temp, vector<string> & ans, unordered_map<int, string> mp){
        if(temp.size() == digits.size()){
            ans.push_back(temp);
            return;
        }
        int digi = digits[idx]-'0';
        string str = mp[digi];
        for(int i = 0; i<str.size() ;i++){
            temp.push_back(str[i]);
            backtrack(digits, idx+1, temp, ans, mp);

            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> mp;
        string temp;
        vector<string> ans;
        int idx = 0;
        mp = {{2, "abc"},
                  {3, "def"},
                  {4, "ghi"},
                  {5, "jkl"},
                  {6, "mno"},
                  {7, "pqrs"},
                  {8, "tuv"},
                  {9, "wxyz"}};
        backtrack(digits, idx, temp, ans, mp);
        return ans;
   }
};