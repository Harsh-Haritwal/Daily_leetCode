class Solution {
public:
    void findComSum(vector<int>& nums, int target, vector<int>& temp,
                    vector<vector<int>>& ans, int idx) {
        if(target < 0){
            return;
        }
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (idx >= nums.size()) {
            return;
        }

        // if (nums[idx] <= target) {
            temp.push_back(nums[idx]);
            findComSum(nums,  target - nums[idx], temp, ans, idx);
            temp.pop_back();
            findComSum(nums, target, temp, ans, idx + 1);
        // }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int idx = 0;
        findComSum(candidates, target, temp, ans, idx);
        return ans;
    }
};