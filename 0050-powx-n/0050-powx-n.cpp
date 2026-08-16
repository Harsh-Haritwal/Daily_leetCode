class Solution {
public:

    double power(double x, double& ans, long long N){
        if(N == 0){
            return ans*1;
        }
        if(N%2 ==1){
            ans = ans * x;
        }
        x *= x;
        N = N/2;
        power(x, ans, N);
        return ans;
    }
    double myPow(double x, int n) {
        double ans = 1;
        long long N = n;
        if(n < 0){
            x = 1/x;
            N = -N;
        }
        power(x,ans,N);
        return ans;
    }
};