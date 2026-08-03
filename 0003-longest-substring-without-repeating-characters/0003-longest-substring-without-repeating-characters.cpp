class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r =0 ,ans =0;
        vector<int> h(255, -1);
        while(r < s.size()){
            if( h[s[r] != -1]){
                l = max(l, h[s[r]]+1);
            }
            h[s[r]] = r;
            ans= max(ans, r-l+1);
            r++;

        }
        return ans;
    }
};