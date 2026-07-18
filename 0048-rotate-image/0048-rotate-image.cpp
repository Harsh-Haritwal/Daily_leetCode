class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>newMatrix(n, vector<int>(n));
        int itr = n-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               newMatrix[j][itr] =  matrix[i][j] ;
            }
                itr--;
        }
        matrix = newMatrix;
    }
};