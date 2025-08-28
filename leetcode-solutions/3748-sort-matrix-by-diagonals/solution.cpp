class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int index= 0; index< n; index++) {
            int i = index;
            int j = 0;
            vector<int>temp;
            while( i < n && j < n) {
                temp.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(temp.begin(),temp.end(),greater<int>());
            i= index;
            j = 0;
            int a = 0;
            while( i < n && j < n) {
                grid[i][j]= temp[a++];
                i++;
                j++;
            }

        }
        for(int col= 1; col< n; col++) {
            int i = 0;
            int j = col;
            vector<int>temp;
            while( i < n && j < n) {
                temp.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(temp.begin(),temp.end());
            i= 0;
            j = col;
            int a = 0;
            while( i < n && j < n) {
                grid[i][j]= temp[a++];
                i++;
                j++;
            }

        }
        return grid;
    }
};
