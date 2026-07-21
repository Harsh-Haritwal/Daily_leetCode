class Solution {
public:

    bool isCapacity(int mid, vector<int>weights, int days){
        int cal = 0;
        int count = 1;
        int it;
        for(int it: weights){
            

            if(cal+it > mid){
                count++;
                cal = it;
            }else{
                cal += it;
            }
        }

        if(count <= days){
            return true;
        }
        return false;
    }


    int shipWithinDays(vector<int>& weights, int days) {
        int max = INT_MIN;
        int sum = 0;
        for(int it: weights){
            if(it >max ){
                max = it;
            }
            sum = sum + it;
        }
        int st = max;
        int end = sum;
        int ans = 0;
        while(st<=end){
            int mid = st+(end-st)/2;

            if(isCapacity(mid, weights, days)){
                ans = mid;
                end = mid-1;
            }else{
                st = mid+1;
            }
        }
        return ans;
    }
};