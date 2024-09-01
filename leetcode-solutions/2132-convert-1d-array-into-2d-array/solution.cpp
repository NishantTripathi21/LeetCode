class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
         // Check if the total number of elements match
        if (original.size() != m * n) {
            return {}; // Return an empty 2D array if impossible
        }
    
        // Construct the 2D array
        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i][j] = original[i * n + j];
            }
        }
    
    return result;
    }
};
