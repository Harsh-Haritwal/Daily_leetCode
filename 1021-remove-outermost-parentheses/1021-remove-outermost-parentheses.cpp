class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int count = 0;
        for(int i = 0; i< s.size(); i++){
            int prev = count;
            if(s[i] == '('){
                count++;
            }else if(s[i] == ')'){
                count--;
            }
            if( prev != 0 && count >= 1){
                ans += s[i];
            }
        }
        return ans;
    }
};