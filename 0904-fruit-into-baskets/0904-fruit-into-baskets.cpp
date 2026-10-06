class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> st;
        int lt = 0;
        int rt = 0;
        int bucket = 0;
        int ans = 0;
        while (rt < fruits.size()) {

            if (st.find(fruits[rt]) == st.end()) {
                bucket++;
            }
            st[fruits[rt]]++;
            if (bucket > 2 ) {

                st[fruits[lt]]--;
                if(st[fruits[lt]] == 0){
                    bucket--;
                    st.erase(fruits[lt]);
                }
                
                lt++;
            }

            ans = max(ans, rt - lt+1 );
            rt++;
        }
        return ans;
    }
};