class Solution {
public:

    vector<int> rightBoundry(vector<int>& heights){
        stack<int> st;
        vector<int> ans(heights.size());
        for(int i = heights.size()-1; i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = heights.size();
            }else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> leftBoundry(vector<int>& heights){
        stack<int> st;
        vector<int> ans(heights.size());
        for(int i = 0; i<heights.size();i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
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



    int largestRectangleArea(vector<int>& heights) {
        vector<int> RB = rightBoundry(heights);
        vector<int> LB = leftBoundry(heights);
        int area = 0;
        for(int i = 0; i<heights.size();i++){
            int height = heights[i];
            int width =  RB[i]-LB[i]-1;
            area = max(area, height*width);
        }
        return area;
    }
};