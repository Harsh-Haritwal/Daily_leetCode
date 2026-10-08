class Solution {
public:

    int solve(vector<int> nums, int k){
        if(k < 0){
            return 0;
        }
        int rt = 0;
        int lt = 0;
        int count = 0;
        int ans = 0;
        while(rt < nums.size()){
            if(nums[rt]%2 != 0){
                count++;
            }
            while(count > k){
                if(nums[lt]%2 != 0)count--;
                lt++;
            }
            if(count <= k && nums[rt]%2 != 0){
                ans += rt-lt+1;
            }else if (count <= k ){
                ans += rt-lt;
            }
            rt++;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k)-solve(nums,k-1);
    }
};