class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // if(nums.size() == 0) return 0;
        // if(nums.size() == 1){
        //     if(nums[0] == val) return 0;
        //     return 1 ;
        // }
        int k = 0;
        int count = 0;
        for(int i = 0; i<nums.size();i++){
            if(nums[i]!=val){
               nums[k] = nums[i];
               k++;
               count++;
            }
        }
        return count ;
    }
};