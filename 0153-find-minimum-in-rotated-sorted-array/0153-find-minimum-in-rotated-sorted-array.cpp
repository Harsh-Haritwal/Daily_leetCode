class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0;
        int end = nums.size()-1;
        int min = INT_MAX;
        while(st<=end){
            int mid = st+(end-st)/2;

            if(nums[mid] < min){
                min = nums[mid];
            }
            else if (nums[mid]  <=  nums[end]){
                end = mid-1;
            }else{
                st = mid+1;
            }
        }
        return min;
    }
};