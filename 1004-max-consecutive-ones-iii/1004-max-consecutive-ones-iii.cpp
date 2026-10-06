class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int lt = 0;
        int rt = 0;
        int ans = 0;
        int countOfZero = 0;
        while( rt < nums.size()){
            if(countOfZero == k && nums[rt] != 1){
                while(nums[lt] != 0){
                    lt++;
                }
                lt++;
                countOfZero--;
            }
            if(nums[rt] == 0) countOfZero++;
            ans = max(ans, rt-lt+1);
            rt++;
        }
        return ans;
    }
};