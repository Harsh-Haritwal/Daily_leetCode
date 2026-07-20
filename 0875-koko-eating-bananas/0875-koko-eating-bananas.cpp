class Solution {
public:

    bool finish(int mid, vector<int>piles, int h){
        long long  totalHours = 0;
        for(int p : piles){
            int q = p/mid;
            int r = 0;
            if(p%mid > 0){
                r = 1;
            }
            totalHours = totalHours +  q+r;
        }
        if(totalHours <= h){
            return true;
        }
        return false;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int n = piles.size()-1;
        int st = 1;
        int end = piles[n];
        int k = 0;
        while(st<=end){
            int mid = st+(end-st)/2;
            if(finish(mid, piles, h)){
                k = mid;
                end = mid-1;
            }else{
                st = mid+1;
            }
        }

        return k;
    }
};