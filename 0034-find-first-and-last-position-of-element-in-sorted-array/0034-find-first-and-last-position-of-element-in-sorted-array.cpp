class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        vector<int> ans(2);
        ans[0] = -1;
        ans[1] = -1;
        while(low<=high){
            if( nums[low] == target && nums[high] == target){
                ans[0] = low;
                ans[1] = high;
                return ans;
            }else if(nums[low] == target && nums[high] != target){
                ans[0] = low;
                high--;
            }else if (nums[low] != target && nums[high] == target){
                ans[1] = high;
                low++;
            }else{
                low++;
                high--;
            }
        }

        return ans;
    }
};