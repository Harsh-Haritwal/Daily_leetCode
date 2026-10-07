class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
            return "";
        unordered_map<char, int> tchars;
        for(int i = 0; i< t.size();i++){
            tchars[t[i]]++;
        }
        int tSize = tchars.size();
        int characters = 0;
        int start = 0;
        
        int lt = 0;
        int rt = 0;
        int minSize = INT_MAX;
        while (rt < s.size()) {
            
            if(tchars.find(s[rt]) != tchars.end()){
                tchars[s[rt]]--;
                if(tchars[s[rt]] == 0) characters++;
            }
            while(tSize == characters){
                if(minSize  > rt-lt+1){
                    minSize = rt-lt+1;

                start = lt;
                }
                if(tchars.find(s[lt]) != tchars.end()){
                    tchars[s[lt]]++;
                    if(tchars[s[lt]] == 1) characters--;
                }
                lt++;
            }
            rt++;

        }
        return minSize == INT_MAX? "" : s.substr(start, minSize);
    }
};