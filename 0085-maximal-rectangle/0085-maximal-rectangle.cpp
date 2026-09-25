class Solution {
public:

    vector<int> findNSE(vector<int>& matrix){
        stack<int> st;
        vector<int> ans(matrix.size());
        for(int i = matrix.size()-1; i>=0;i--){
        while(!st.empty() && matrix[st.top()] >= matrix[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = matrix.size();
        }else{
            ans[i] = st.top();
        }
        st.push(i);

        }
        return ans;
    }

    vector<int> findPSE(vector<int>& matrix){
        stack<int> st;
        vector<int> ans(matrix.size());
        for(int i = 0; i<matrix.size();i++){
        while(!st.empty() && matrix[st.top()] > matrix[i]){
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


    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        vector<int> temp(matrix[0].size(),0);
        for (int i = 0; i < matrix.size(); i++) {

            for(int j = 0; j<matrix[i].size();j++){
                if(matrix[i][j]-'0' == 1){

                temp[j] = temp[j] + 1;
                }else{
                    temp[j] = 0;
                }
            }
            vector<int> NSE = findNSE(temp);
            vector<int> PSE = findPSE(temp);

            int area = 0;
            for (int j = 0; j < temp.size(); j++) {
                int height = temp[j];
                int width = NSE[j] - PSE[j] - 1;
                area = max(area, height * width);
            }
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};