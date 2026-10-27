class Solution {
public:
    vector<string> createGrid(int m, int n) {
        
        string s = ".";
        for(int i=0;i<n-1;i++){
            s.push_back('#');
        }
        vector<string> str(m-1,s);
        s=".";
        for(int i=0;i<n-1;i++){
            s.push_back('.');
        }
        str.push_back(s);
        return str;


    }
};