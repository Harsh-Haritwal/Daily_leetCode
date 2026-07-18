class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        if(n == 1){
            return nums[0];
        }
        for(int i=0;i<n;i++){
            int curr = nums[i];
            ans = max(ans,curr);
            for(int j = i+1;j<n;j++){
                curr *= nums[j];
                ans = max(ans,curr);
            }
        }
        return ans;
    }
};