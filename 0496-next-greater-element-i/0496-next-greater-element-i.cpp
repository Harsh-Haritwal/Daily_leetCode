class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> nge;
        vector<int> ans;
        unordered_map<int,int> mp;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && !(nums2[i] < st.top())) {
                st.pop();
            }
            if (st.empty())
                nge.push_back(-1);
            else
                nge.push_back(st.top());
            st.push(nums2[i]);
        }
        for (int j = 0; j < nums2.size(); j++) {
            mp[nums2[j]] = nge[nums2.size() - 1 - j];
        }
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};