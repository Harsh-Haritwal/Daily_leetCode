class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;

        mp.insert({'I', 1});
        mp.insert({'V', 5});
        mp.insert({'X', 10});
        mp.insert({'L', 50});
        mp.insert({'C', 100});
        mp.insert({'D', 500});
        mp.insert({'M', 1000});

        int count = 0;
        int last = 1000;
        for (int c : s) {
            for (auto& it : mp) {
                if(c == it.first){
                   if( last < it.second){
                    count = count + it.second - 2*last;
                   }else{
                    count = count + it.second;
                   }
                    last = it.second;
                }
            }
        }

        return count;
    }
};