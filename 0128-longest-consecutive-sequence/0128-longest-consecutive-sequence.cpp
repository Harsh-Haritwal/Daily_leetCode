class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        else if( n==1){
            return 1;
        }
        int diff = 1;
        int seq = 1;
        int maxSeq = 1;
        for (int i = 1; i < n ; i++) {
            if (nums[i] - nums[i-1] == diff) {
                seq++;

            } 
            else if ( nums[i] - nums[i-1] == 0) {
                    continue;
            }else if (nums[i] - nums[i-1] != diff){
                seq = 1;
            }
            
            maxSeq = max(maxSeq, seq);
        }
        return maxSeq;
    }
};