class Solution {
public:
    int bfs(vector<vector<int>>& grid) {
        int n = grid.size();
        //vector<vector<int>>vis(n,vector<int>(n,0));
        queue<pair<int,int>>q; //{row,col}

        for(int i= 0; i< n; i++) {
            for(int j= 0; j< n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i,j});
                }
            }
        }
        if(q.size() == n*n || !q.size())return -1;
        vector<pair<int,int>>directions = {{0,1},{1,0},{-1,0},{0,-1}};
        int steps = -1;
        int dis = 0;
        while(!q.empty()) {
            int size = q.size();
            steps++;
            while(size--) {
                auto [row,col] = q.front();
                q.pop();
                for(auto [dx,dy]: directions) {
                    int nrow = row+dx;
                    int ncol = col + dy;
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0) {
                        grid[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        return steps;
    }
    int maxDistance(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};
