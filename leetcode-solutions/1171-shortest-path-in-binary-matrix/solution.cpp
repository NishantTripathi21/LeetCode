class Solution {
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        queue<pair<pair<int,int>,int>>q; // {{x,y},dist}
        if( grid[source.first][source.second] == 1 || grid[destination.first][destination.second])return -1;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[source.first][source.second] = 0;
        q.push({{source.first,source.second},1});
        //vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
        while( !q.empty()) {
            auto temp = q.front();
            q.pop();
            int x = temp.first.first;
            int y = temp.first.second;
            int dis = temp.second;
            dist[x][y] = dis;
            //cout<<" x: "<<x<<" y: "<<y<<" dis: "<<dis<<endl;
            for( int i = -1; i<= 1; i++) {
                for( int j = -1; j<= 1; j++) {
                    int dx = i;
                    int dy = j;
                    int nx = x + dx;
                    int ny = y + dy;
                    if( nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0) {
                        if(dist[nx][ny] > dis + 1) {
                            dist[nx][ny] = dis + 1;
                            q.push({{nx,ny},dis+1});
                        }
                    }
                }
            }
        }
        return dist[destination.first][destination.second] == 1e9? -1:dist[destination.first][destination.second]  ;
        
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return shortestPath(grid,{0,0},{n-1,m-1});
    }
};
