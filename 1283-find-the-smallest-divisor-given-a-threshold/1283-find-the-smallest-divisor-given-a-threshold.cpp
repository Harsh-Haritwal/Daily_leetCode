class Solution {
public:

    bool canDivide(vector<int>nums, int mid , int threshold){
        int sum = 0;
        for(int el: nums){
            sum  = sum +  el/mid;
            if(el%mid != 0){
                sum++;
            }
        }
        if(sum <= threshold){
            return true;
        }
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(), nums.end());
        int st = 1;
        int end = nums[nums.size()-1];
        int ans = 0;

        while(st<=end){
            int mid = st+(end-st)/2;

            if(canDivide(nums, mid, threshold)){
                ans = mid;
                end= mid-1;
            }else{
                st = mid+1;
            }
        }
        return ans;
    }
};