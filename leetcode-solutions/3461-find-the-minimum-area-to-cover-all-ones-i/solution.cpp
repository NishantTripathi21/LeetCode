class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minX = INT_MAX;
        int minY = INT_MAX;
        int maxX = INT_MIN;
        int maxY = INT_MIN;
        for(int i= 0; i< grid.size(); i++) {
            for(int j= 0; j< grid[0].size(); j++) {
                if(grid[i][j]== 1) {
                    minX= min(minX,i);
                    minY = min(minY,j);
                    maxY = max(maxY,j);
                    maxX = max(maxX, i);
                }
            }
        }
        return (maxX - minX + 1) * (maxY - minY + 1); 
    }
};
