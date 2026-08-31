class Solution {
public:
    vector<vector<int>> findSubsets(vector<int>& nums, int idx, vector<int> & temp, vector<vector<int>> & ans){
        
        if(idx == nums.size()){
            ans.push_back(temp);
            return ans;
        }
        
        temp.push_back(nums[idx]);
        findSubsets(nums, idx + 1, temp, ans);

        temp.pop_back();

        findSubsets(nums, idx+1, temp, ans);
        return ans;

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        int idx = 0;
        return findSubsets(nums,idx,temp, ans);
    }
};