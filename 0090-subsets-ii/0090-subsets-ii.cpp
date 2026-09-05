class Solution {
public:

    void subset(vector<int>& nums, vector<int>&temp, vector<vector<int>>& ans, int idx){
        if(idx == nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        subset(nums, temp, ans, idx+1);
        temp.pop_back();
        while(idx < nums.size()-1 && nums[idx+1] == nums[idx]){
            idx++;
        }
        subset(nums, temp, ans, idx+1);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>temp;
        vector<vector<int>>ans;
        int idx = 0;
        subset(nums,temp, ans, idx);
        return ans;
    }
};