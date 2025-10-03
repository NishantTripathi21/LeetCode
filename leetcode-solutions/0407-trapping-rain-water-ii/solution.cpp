class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if(m == 0) return 0;
        int n = heightMap[0].size();
        if(n == 0) return 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>,greater<>> pq; //{height,{i,j}}
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n-1], {i, n-1}});
            visited[i][0] = visited[i][n-1] = true;
        }
        for (int j = 0; j < n; j++) {
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[m-1][j], {m-1, j}});
            visited[0][j] = visited[m-1][j] = true;
        }

        vector<pair<int,int>>directions= {{1,0},{0,1},{-1,0},{0,-1}};
        int water = 0;
        while(!pq.empty()) {
            auto [h, cell] = pq.top();
            pq.pop();
            int x = cell.first, y = cell.second;
            for(auto [dx,dy] : directions){
                int nx = x + dx;
                int ny = y + dy;
                if(nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                water += max(0, h - heightMap[nx][ny]);
                pq.push({max(h, heightMap[nx][ny]), {nx, ny}}); // updated height
            }
        }

        return water;
    }

};
