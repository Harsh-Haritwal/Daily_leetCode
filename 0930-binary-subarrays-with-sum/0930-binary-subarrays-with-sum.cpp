class Solution {
public:

    int solve(vector<int> nums, int goal){
        if(goal < 0){
            return 0;
        }
        int rt= 0;
        int lt = 0;
        int sum = 0;
        int ans = 0;

        while(rt < nums.size()){
            sum += nums[rt];
            while(sum > goal){
                sum -= nums[lt];
                lt++;
            }
            if(sum <= goal){
                ans += rt-lt+1;
            }
            rt++;
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums,goal) - solve(nums, goal-1);
    }
};