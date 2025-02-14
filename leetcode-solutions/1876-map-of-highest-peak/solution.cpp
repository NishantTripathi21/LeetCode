class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>>result(m, vector<int>(n,-1));
        queue<pair<int, int>> q;
        for( int i = 0; i< m; i++) {
            for( int j = 0; j< n; j++) {
                if( isWater[i][j] == 1) {
                    q.push({i,j});
                    result[i][j] = 0;
                }
            }
        }
        vector<pair<int,int>>direction = {{0,1},{1,0},{-1,0},{0,-1}};
        while( !q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            for(auto [dx,dy]: direction)  {
                int nx = x + dx;
                int ny = y + dy;
                if( nx >= 0 && nx < m && ny >= 0 && ny < n && result[nx][ny] == -1) {
                    result[nx][ny] = result[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
        return result;
    }
};
