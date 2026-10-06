class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<int> st;
        int lt = 0;
        int rt = 0;
        int maxLen = 0;
        string str = "";
        while(rt< s.size()){
            while(st.find(s[rt]) != st.end()){
                str.erase(0,1);
                st.erase(s[lt]);
                lt++;
            }
            str += s[rt];
            st.insert(s[rt]);
            maxLen = max (maxLen, rt-lt+1);
            rt++;
        }
        return maxLen;
    }
};