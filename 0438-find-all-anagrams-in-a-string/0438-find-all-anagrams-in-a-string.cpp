class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.size() < p.size())
            return ans;
        int n = p.size();
        vector<int> pFreq(26);
        vector<int> winFreq(26);
        for (int i = 0; i < n; i++) {
            pFreq[p[i]-'a']++;
        }

        int left = 0;

        for(int i = 0; i<s.size();i++) {
            winFreq[s[i]-'a']++;

            if(i-left+1>n){
            winFreq[s[left]-'a']--;
            left++;
            }

            if(i-left+1 == n){
                if(pFreq == winFreq){
                    ans.push_back(left);
                }
            }
        }
        return ans;
    }
};