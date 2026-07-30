class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int shift = 0;shift < s.size() ;shift++){
            bool ans = true;

            for(int i =0 ;i<s.size() ; i++){

                if(s[(i+shift) % s.size()] != goal[i]){
                    ans  = false;
                    break;
                }

            }

            if(ans){
                return ans;
            }
        }

        return false;
    }
};