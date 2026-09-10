class Solution {
public:

    bool isPalindrome(string s, int st, int end){
        while(st <= end){
            if(s[st] == s[end]){
                st++;
                end--;
            }else{
                return false;
            }
        }
        return true;
    }

    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i< s.size();i++){
            for(int j = i; j< s.size();j++){
                if(i == j){
                    count++;
                    continue;
                }
                else if(isPalindrome(s, i , j )){
                    count++;
                }
            }
        }
        return count;
    }
};