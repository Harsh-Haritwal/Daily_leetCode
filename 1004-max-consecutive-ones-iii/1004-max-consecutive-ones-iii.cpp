class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int lt = 0;
        int rt = 0;
        int ans = 0;
        int countOfZero = 0;
        while (rt < nums.size()) {
            if (nums[rt] == 0) countOfZero++;
            if (countOfZero > k) {
                if (nums[lt] == 0) {
                    countOfZero--;
                }
                lt++;
                rt++;
                continue;
            }
            ans = max(ans, rt - lt + 1);
            rt++;
        }
        return ans;
    }
};