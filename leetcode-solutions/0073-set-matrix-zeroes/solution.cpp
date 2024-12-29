class Solution {
public:
    void method1( vector<vector<int>>& matrix){
        // tc - O(m*n) + O(m*n)
        // sc- O(m+n)
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>col(n,1);
        vector<int>row(m,1);
        for( int i = 0 ; i < m ; i++){
            for( int j = 0 ; j < n ; j++){
                if( matrix[i][j] == 0){
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }  
        for( int i = 0 ; i<m ; i++){
            for( int j = 0 ; j<n ; j++){
                if( row[i] == 0 || col[j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        method1(matrix);   
    }
};
