class Solution {
public:

    void findUniCom(vector<int>& nums, int target, vector<int>& temp, vector<vector<int>> &ans , int idx){
        if(target < 0){
            return;
        }
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(idx == nums.size()){
            return;
        }

        temp.push_back(nums[idx]);
        findUniCom(nums, target-nums[idx], temp, ans, idx+1);
        while(idx < nums.size()-1 && nums[idx+1] == nums[idx]){
            idx++;
        }
        temp.pop_back();
        findUniCom(nums, target, temp, ans, idx+1);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int idx = 0;
        findUniCom(candidates, target, temp, ans, idx);
        return ans;
    }
};