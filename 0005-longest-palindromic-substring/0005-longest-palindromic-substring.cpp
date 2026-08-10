class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0)
            return "";
        else if (n == 1)
            return s;

        int start = 0;
        int length = 1;
        string ans;

        for (int i = 0; i < n; i++) {

            int left = i - 1;
            int right = i + 1;
            while (left >= 0 && right <= n - 1) {
                if (s[left] == s[right]) {
                    if (right - left + 1 > length) {
                        start = left;
                        length = right - left + 1;
                    }
                    left--;
                    right++;
                } else {
                    break;
                }
            }

            left = i;
            right = i + 1;
            while (left >= 0 && right <= n - 1) {
                if (s[left] == s[right]) {
                    if (right - left + 1 > length) {
                        start = left;
                        length = right - left + 1;
                    }
                    left--;
                    right++;
                } else {
                    break;
                }
            }
        }

        for (int i = start; i < start + length; i++) {
            ans.push_back(s[i]);
        }

        return ans;
    };
};