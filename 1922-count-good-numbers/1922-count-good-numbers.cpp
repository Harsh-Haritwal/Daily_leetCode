class Solution {
public:

    void pow(long long  x, long long y,long long& ans){
        if(y == 0){
           return;
        }
        if(y % 2 == 1){
            
        ans = (ans * x)%(1000000007);
        }
        x  = (x*x)%(1000000007);
        y = y/2;
        pow(x, y, ans);
    }


    int countGoodNumbers(long long n) {
        long long a1  = 1;
        long long a2 = 1;
        pow(5,(n+1)/2, a1); 
        pow(4,n/2, a2); 
        long long ans =(a1*a2)%(1000000007);
        
        return ans;
        // return a1;
    }
};