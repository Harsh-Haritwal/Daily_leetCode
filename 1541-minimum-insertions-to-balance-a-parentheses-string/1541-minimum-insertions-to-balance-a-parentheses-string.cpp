class Solution {
public:
    int minInsertions(string s) {
        int result = 0;
        int i = 0;
        int count = 0;
        while( i < s.size()){
            if(s[i] == '('){count++;i++;}
            else{
                if(count >0){
                    count--;
                }else{
                    result++;
                }
                if(i+1 < s.size() && s[i+1] == ')'){
                    i += 2;
                }else{
                    result++;
                    i++;
                }
            }
        }
        return result + count*2;
    }
};