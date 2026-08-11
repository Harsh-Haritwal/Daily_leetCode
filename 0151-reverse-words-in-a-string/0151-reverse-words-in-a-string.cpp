class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = n - 1;
        int j = n - 1;
        string ans;
        while (s[i] == ' ') {
            i--;
            j--;
        }

        while (i >= 0 && j >= 0) {
            while (j >= 0 && s[j] != ' ') {
                j--;
            }
            for (int k = j + 1; k <= i; k++) {
                ans = ans + s[k];
            }
            if (!(j <= 0) && s[j-1] != ' ') {
                ans += ' ';
            }

            i = j-1;
            j--;
            
        }
        return ans;
    }
};