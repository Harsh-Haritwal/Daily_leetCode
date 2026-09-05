class Solution {
public:
    void subseq(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp,
                int siz, int idx) {
        if (temp.size() >= siz) {
            ans.push_back(temp);
        }
        unordered_set<int> st;
        for (int i = idx; i< nums.size(); i++) {

            if ((temp.empty() || nums[i] >= temp.back()) &&
                (st.find(nums[i]) == st.end())) {

                temp.push_back(nums[i]);
                st.insert(nums[i]);
                subseq(nums, ans, temp, siz, i + 1);

                temp.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int siz = 2;
        int idx = 0;
        // int prev = nums[0];
        subseq(nums, ans, temp, siz, idx);
        return ans;
    }
};