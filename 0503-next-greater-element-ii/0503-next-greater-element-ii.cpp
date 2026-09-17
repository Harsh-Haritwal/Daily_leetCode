class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] < nums[j]) {
                    ans.push_back(nums[j]);
                    count++;
                    break;
                }
            }
            if (count == 0) {
                for (int j = 0; j < i; j++) {
                    if (nums[i] < nums[j]) {
                        ans.push_back(nums[j]);
                        count++;
                        break;
                    }
                }
            }
            if(count == 0){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};