class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st = 0;
        int end = nums.size() - 1;

        while (st <= end) {

            int mid = st+(end-st)/2;

            if(nums.size() == 1) return nums[0]; 
            if(mid == 0) return nums[0];
            if(mid == nums.size()-1) return nums[mid];



            if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
                return nums[mid];
            else if (nums[mid - 1] == nums[mid]) {
                if ((mid - st) % 2 == 0) {
                    end = mid - 2;
                } else {
                    st = mid + 1;
                }
            } else {
                if ((mid - st) % 2 == 0) {
                    st = mid + 2;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};