class Solution {
public:
    vector<int> method( vector<vector<int>>& grid){
        int m = grid.size();
        vector<int>ans;
        int n = grid[0].size();
        int col = 0;
        int row = 0;
        int flag = true; // left to right
        while( row < m){
            int element = grid[row][col];
            ans.push_back(element);
            if( flag ){
                if( col +2 == n){
                    row = row+1;
                    col = n - 1;
                    flag = !flag;
                }
                else if( col == n-1){
                    row++;
                    col = col - 1;
                    flag = !flag;
                }
                else{
                    col = col+2;
                }
            }
            else{
                if( col == 1){
                    row++;
                    col = 0;
                    flag =!flag;
                }
                else if( col == 0){
                    col = 1;
                    row++;
                    flag = !flag;
                }
                else{
                    col =  col -2;
                }
            }
        }
        return ans;
    }
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        return method(grid);
    }
};
