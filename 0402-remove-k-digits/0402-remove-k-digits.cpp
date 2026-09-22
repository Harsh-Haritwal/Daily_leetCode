class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        vector<char> ans;
        string str;

        if (k == num.size()) {
            return "0";
        }

        for (int i = 0; i < num.size(); i++) {
            while (!st.empty() && k > 0 && st.top() - '0' > num[i] - '0') {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while (!st.empty() && k != 0) {
            st.pop();
            k--;
        }

        // while (!st.empty() && st.top() == '0') {
        //     st.pop();
        // }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        while(!ans.empty() && ans.size() != 1 && ans.back() - '0' == 0){
            ans.pop_back();
        }
        while(!ans.empty()){
            str.push_back(ans.back());
            ans.pop_back();
        }

        return str;
    }
};