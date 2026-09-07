class Solution {
public:
    void backtrack(int n, string temp, vector<string>& ans, int open,
                   int close) {
        if (temp.size() == n * 2) {
            ans.push_back(temp);
            return;
        }
        if (open < n) {

            temp.push_back('(');
            backtrack(n, temp, ans, open+1, close);
            temp.pop_back();
        }
        if (close < open) {
            temp.push_back(')');
            backtrack(n, temp, ans, open, close+1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        int open = 0;
        int close = 0;
        backtrack(n, temp, ans, open, close);
        return ans;
    }
};