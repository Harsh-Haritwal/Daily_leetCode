class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while( i < n && s[i] == ' '){
            i++;
        }
        int sign = 1;
        if(s[i] == '-' || s[i] == '+'){
            if(s[i] == '-'){
                sign = -1;
            }
            i++;
        }
        long long ans = 0;
        while(s[i] >= '0' && s[i] <='9' && i < n){
            if((ans > INT_MAX/10) ||( ans == INT_MAX/10 && s[i] > '7')){
                if( sign == -1){
                    return INT_MIN;
                }
                return INT_MAX;
            }
            ans = ans*10 + s[i]-'0';
            i++;
        }
        if(sign == -1){
            return sign*ans;
        }
        return ans;
    }
};