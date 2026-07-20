class Solution {
public:

    bool canMake(int mid, vector<int> bloomDay, int m, int k){
        int count = 0;
        int maxCount = 0;
        int bou = 0;
        for(int el : bloomDay){
            if(el <= mid){
                count++;
            }else{
                count = 0;
            }
            if(count == k){
                bou++;
                count = 0;
            }
        }

        if(bou >= m){
            return true;
        }
        return false;
    }



    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if((long long)m*k > n) return -1;

        int minimum = INT_MAX;
        int maximum = INT_MIN;

        for(int el: bloomDay){
            if(minimum > el){
                minimum = el;
            }
            if(maximum < el){
                maximum = el;
            }
        }

        int st = minimum;
        int end = maximum;
        int min = 0;

        while(st <= end){
            int mid = st+(end-st)/2;

            if(canMake(mid, bloomDay, m,k)){
                min  = mid;
                end = mid-1;
            }else{
                st = mid+1;
            }
        }
        return min;
    }
};