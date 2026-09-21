class Solution {
public:

    vector<int> findNGE(vector<int> & nums){
        int N = nums.size();
        stack<int> st;
        vector<int> ans(nums.size());
        for(int i = nums.size()-1; i>= 0; i--){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = N;
            }else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> findNSE(vector<int> & nums){
        int N = nums.size();
        stack<int> st;
        vector<int> ans(nums.size());
        for(int i = nums.size()-1; i>= 0; i--){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = N;
            }else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> findPGE(vector<int> & nums){
        int N = nums.size();
        stack<int> st;
        vector<int> ans(nums.size());
        for(int i = 0; i< nums.size(); i++){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> findPSE(vector<int> & nums){
        int N = nums.size();
        stack<int> st;
        vector<int> ans(nums.size());
        for(int i = 0; i< nums.size(); i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }




    long long subArrayRanges(vector<int>& nums) {

        vector<int> NSE = findNSE(nums);
        vector<int> NGE = findNGE(nums);
        vector<int> PSE = findPSE(nums);
        vector<int> PGE = findPGE(nums);

        vector<long long> LR(nums.size());
        for( int i =0; i<nums.size();i++){
            int left = i - PSE[i];
            int right = NSE[i] - i;
            LR[i] = right*left*1ll*nums[i];
        }
        vector<long long> UR(nums.size());
        for( int i =0; i<nums.size();i++){
            int left = i - PGE[i];
            int right = NGE[i] - i;
            UR[i] = right*left*1ll*nums[i];
        }
        long long ans = 0;
        for(int i = 0; i< nums.size() ;i++){
            ans = ans  + (UR[i] - LR[i]);
        }
        return ans;
    }
};