class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                int max = 0;
                int min = 501;
                freq[s[j] - 'a']++;
                for (int el : freq) {
                    if (el > max) {
                        max = el;
                    }
                    if (el > 0 && el < min) {
                        min = el;
                    }
                }
                ans += max - min;
            }
        }
        return ans;
    }
};