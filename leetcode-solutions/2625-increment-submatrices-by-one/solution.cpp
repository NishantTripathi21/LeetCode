class Solution {
public:
    vector<vector<int>> method1( int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans( n, vector<int>(n,0));
        // Iterate through each query to mark the increments in the grid.
        for( auto i: queries){
            int r1 = i[0];
            int r2 = i[2];
            int c1 = i[1];
            int c2 = i[3];
            // Increment the starting column for each row in the range [r1, r2].
            for ( int r = r1; r<= r2; r++){
                ans[r][c1]++;
                // Decrement the element right after the ending column, if within bounds.
                if( (c2+1) < n)ans[r][c2+1]--;
            }
        }
        // Propagate the increments horizontally to apply the range increment effect.
        for( int i = 0; i< n; i++){
            for( int j = 1; j< n; j++){
                ans[i][j] += ans[i][j-1];
            }
        }
        return ans;
    }
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        return method1(n, queries);
    }
};
