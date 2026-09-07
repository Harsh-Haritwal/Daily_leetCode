class Solution {
public:

    void backtrack(vector<int>& nums, vector<int> &temp, vector<vector<int>> &ans, map<vector<int>, bool> &mp, vector<bool> & used ){

        if(nums.size() == temp.size()){
            if(mp.find(temp) == mp.end()){
                ans.push_back(temp);
                mp.insert({temp, true});
            }
            return;
        }


        for(int i = 0; i< nums.size(); i++){

            if(used[i] == false){

                temp.push_back(nums[i]);
                used[i] = true;
                backtrack(nums, temp, ans, mp, used);

                temp.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        map<vector<int>, bool> mp;
        vector<bool> used(nums.size(), false);
        backtrack(nums,  temp, ans, mp, used);
        return ans;
    }
};