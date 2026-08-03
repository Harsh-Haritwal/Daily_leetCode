class Solution {
public:

    vector<vector<int>>subset(vector<int> nums, vector<vector<int>>&ans, vector<int>& temp, int i){
        if( i == nums.size()){
            ans.push_back(temp);
            return ans;
        }

        temp.push_back(nums[i]);
        subset(nums, ans, temp, i+1);
        temp.pop_back();
        int idx = i+1;
        while(idx < nums.size() && nums[idx] == nums[idx-1]){
            idx++;
        }
        subset(nums, ans, temp, idx);
        return ans;
    }



    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int> temp;
        int i = 0;

        return subset(nums, ans, temp, i);
    }
};