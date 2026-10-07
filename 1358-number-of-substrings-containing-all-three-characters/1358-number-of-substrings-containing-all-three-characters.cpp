class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastA = -1;
        int lastB = -1;
        int lastC = -1;
        int ans = 0;
        int rt = 0;
        while(rt < s.size()){
            if(s[rt] == 'a') {lastA = rt;}
            else if(s[rt] == 'b') {lastB = rt;}
            else if(s[rt] == 'c') {lastC = rt;}

            if(lastA > -1 && lastB > -1 && lastC > -1){
                int min2 = min({lastA,lastB,lastC});

                ans = ans + min2+1;

            }
            rt++;
        }
        return ans;
    }
};