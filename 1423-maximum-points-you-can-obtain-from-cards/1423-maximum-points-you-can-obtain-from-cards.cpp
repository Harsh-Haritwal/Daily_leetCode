class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int lt = 0;
        int rt = 0;
        int minSum = INT_MAX;
        int arraySum = 0;
        int sum = 0;
        for(int i = 0; i<nums.size();i++){
            arraySum += nums[i];
        }
        if(k == n){
            return arraySum;
        }
        for( rt = 0 ; rt < nums.size()-k;rt++){
            sum = sum+nums[rt];
        }
        minSum = min(minSum, sum);
        while(rt < nums.size()){
            sum = sum - nums[lt];
            lt++;
            sum = sum + nums[rt];
            rt++;
            minSum = min(minSum, sum);
        }
        return arraySum-minSum;
    }
};