class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s;

        if(strs[0] == "") return "";

        for(int i = 0;i<strs[0].size();i++){
            s.push_back(strs[0][i]);
            for(int j =1;j<strs.size();j++){
                if(s[i] != strs[j][i]){
                    s.pop_back();
                    return s;
                }
            }
        }

        return s;
    }
};