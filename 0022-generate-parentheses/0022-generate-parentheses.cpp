class Solution {
public:
    void backtrack(int n, string temp, vector<string>& ans) {
        if (temp.size() == n * 2) {
            stack<char> st;
            for (int i = 0; i < n * 2; i++) {
                if (temp[i] == '(') {
                    st.push('(');
                } else if (temp[i] == ')') {
                    if (!st.empty() && st.top() == '(') {
                        st.pop();
                    }else{
                        return;
                    }
                }
            }
            if(st.empty()){

            ans.push_back(temp);
            }

            return;
        }
        temp.push_back('(');
        backtrack(n, temp, ans);
        temp.pop_back();
        temp.push_back(')');
        backtrack(n, temp, ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        backtrack(n, temp, ans);
        return ans;
    }
};