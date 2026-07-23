class Solution {
public:

    bool isPosible(int mid, vector<int> nums, int k){
        int parts = 1;
        int sum = 0;
        for(int el:nums){
            if((sum + el )<= mid){
                sum += el;
                
            }else if ((sum + el) > mid){
                parts++;
                sum = el;
            }
        }

        if(parts <= k){
            return true;
        }

        return false;
    }



    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        int max = INT_MIN;
        for(int el:nums){
            sum  = sum + el;
            if(el>max){
                max = el;
            }
        }
        int st = max;
        int end = sum;
        int ans = 0;

        while(st<=end){
            int mid = st+(end-st)/2;

            if(isPosible(mid, nums, k)){
                ans= mid;
                end = mid-1;
            }else{
                st = mid+1;
            }
        }

        return ans;
    }
};