class Solution {
public:
    bool checkZeroOnes(string s) {
        int zero = 0;
        int one = 0;
        int maxZ = 0;
        int maxO = 0;
        for(int i = 0; i<s.size();i++){
            if(s[i] == '1'){
                one++;
                zero = 0;
            }else{
                zero++;
                one= 0;
            }
            maxZ = max(maxZ, zero);
            maxO = max(maxO, one);
            
        }
        if(maxO > maxZ){
            return true;
        }
        return false;
    }
};