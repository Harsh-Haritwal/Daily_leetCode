class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> um;
        unordered_set<char> um2;

        for (int i = 0; i < s.size(); i++) {

            if (um.find(s[i]) != um.end()) {

                if (um.find(s[i])->second != t[i]) {
                    return false;
                }
            } else {

                if (um2.find(t[i]) != um2.end()) {
                        return false;
                }
                um.insert({s[i], t[i]});
                um2.insert({t[i]});
            }
        }
        return true;
    }
};