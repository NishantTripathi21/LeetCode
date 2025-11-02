class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int  m = grid.size();
        int n = grid[0].size();
        
        set<pair<int,int>>isY;
        int totalY = 0;
        int totalbg = 0;
        for(int i= 0; i< m/2; i++) {
            isY.insert({i,i});
            isY.insert({i,n-1-i});
        }

        for(int i = m/2; i< m; i++) {
            isY.insert({i,n/2});
        }
        totalY = isY.size();
        totalbg  = m*n - totalY;
        vector<int>yVal(3,0);
        vector<int>bgVal(3,0);

        for(int i= 0; i< m; i++) {
            for( int j = 0; j< n; j++) {
                if(isY.count({i,j})) yVal[grid[i][j]]++;
                else bgVal[grid[i][j]]++;
            }
        }
        int ans = INT_MAX;
        for(int i= 0; i< 3; i++) {
            for(int j = 0; j< 3; j++)  {
                if(i == j)continue;
                int yflip = totalY - yVal[i];
                int bgflip = totalbg - bgVal[j];
                ans = min(ans, bgflip+yflip);
            }
        }
        return ans;
    }
};
