class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n;
        int repeating = -1, missing = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = abs(grid[i][j]); 
                int index = val - 1;

                if (grid[index / n][index % n] < 0) { 
                    repeating = val;
                }
                else {
                    grid[index / n][index % n] = -grid[index / n][index % n];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    missing = i * n + j + 1; 
                }
            }
        }
        return {repeating, missing};
    }
};
