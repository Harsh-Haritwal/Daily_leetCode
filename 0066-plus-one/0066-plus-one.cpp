class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int digit = 0;
        stack<int> st;
        vector<int> ans;
        for(int el : digits){
            st.push(el);
        }
        int carry = 1;
        while(!st.empty()){
            int el = st.top()+carry;
            carry = el/10;
            ans.push_back(el%10);
            st.pop();
        }
        if(carry != 0){
            ans.push_back(carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};