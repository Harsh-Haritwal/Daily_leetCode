class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i =0 ;i <nums1.size();i++){
            int temp;
            for(int j = 0; i<nums2.size();j++){
                if(nums2[j] == nums1[i]){
                    temp = j;
                    break;
                }
            }
            int count = 0;
            for(int k = temp+1; k<nums2.size();k++){
                if(nums2[k] > nums1[i]){
                    ans.push_back(nums2[k]);
                    count++;
                    break;
                }
            }
            if(count == 0 ){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};