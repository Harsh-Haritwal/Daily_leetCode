class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> mergedArr(m + n, 0);

        int P1 = m - 1;
        int P2 = n - 1;
        int P3 = m + n - 1;

        while (P1 >= 0 && P2 >= 0) {

            if (nums1[P1] >= nums2[P2]) {
                mergedArr[P3] = nums1[P1];
                P1--;
                P3--;
            } else {
                mergedArr[P3] = nums2[P2];
                P2--;
                P3--;
            }
        }

        if(P1 >= 0){
            while(P1>= 0){
                mergedArr[P3] = nums1[P1];
                P3--;
                P1--;
            }
        }else{
            while(P2>= 0){
                mergedArr[P3] = nums2[P2];
                P3--;
                P2--;
            }
        }
        double ans = 0;
        if((m+n)%2 == 0){
           int one =  (0+mergedArr.size()-1)/2;

           ans = (double)(mergedArr[one]+mergedArr[one+1])/2;
        }else{
            ans =mergedArr[ (0+(m+n-1))/2];
        }

        return ans;
    }
};