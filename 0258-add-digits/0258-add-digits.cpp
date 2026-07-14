class Solution {

    int solve(int num) {
        if (num <= 0) {
            return num;
        }
        return num%10 + solve(num/10);
    }

public:
    int addDigits(int num) {
        // if(num >=10){
         int ans =    solve(num);
         while(ans >= 10){
            ans = solve(ans); 
         }
        
        return ans;
    }
};