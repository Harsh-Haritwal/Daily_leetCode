class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sz = nums.size();
        int ans = 0;
        for(int i = 0; i<sz;i++ ){
            if(sz%(i+1) == 0){
                ans += nums[i]*nums[i];
            }
        }
        return ans;
    }
};