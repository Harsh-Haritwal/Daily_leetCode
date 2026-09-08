class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> newArray;
        for(int i = 0; i<nums.size();i++){
            if(nums[i]!=val){
                newArray.push_back(nums[i]);
            }
        }
        nums = newArray;
        return newArray.size();
    }
};