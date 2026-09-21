class Solution {
public:

    vector<int> findPSE(vector<int> &arr){
        int N = arr.size();
        stack<int> st;
        vector<int> ans(arr.size());
        for(int i = 0; i<arr.size();i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
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

    vector<int> findNSE(vector<int> &arr){
        int N = arr.size();
        stack<int> st;
        vector<int> ans(arr.size());
        for(int i = arr.size()-1 ; i>=0;i--){
            while(!st.empty() && arr[st.top()] > arr[i]){
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



    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);
        int sum = 0;
        int mod = 1e9+7;
        for(int i = 0; i< arr.size();i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            sum = (sum+(left*right*1ll*arr[i])%mod)%mod;
        }
        return sum;
    }

};