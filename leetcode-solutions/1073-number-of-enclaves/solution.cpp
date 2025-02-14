class Solution {
public:
    void bfs(vector<vector<int>>& board,vector<vector<bool>>&visited, int x, int y) {
        queue<pair<int,int>>q;
        visited[x][y] = true;
        q.push({x,y});
        int n = board[0].size();
        int m = board.size();
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!q.empty()) {
            auto [r,c] = q.front();
            q.pop();
            for( auto [dx,dy] : directions) {
            int nx = r + dx;
            int ny = c + dy;
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && visited[nx][ny] == false && board[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
        
    }
    int numEnclaves(vector<vector<int>>& board) {
        // grid = board
        int n = board[0].size();
        int m = board.size();
        vector<vector<bool>>visited(m, vector<bool>(n,false));
        for( int i = 0; i< n; i++) {
            if( !visited[0][i] && board[0][i] == 1) {
                bfs(board,visited,0,i);
            }
        }
        for( int i = 0; i< n; i++) {
            if( !visited[m-1][i] && board[m-1][i] == 1) {
                bfs(board,visited,m-1,i);
            }
        }
        for( int i = 0; i< m; i++) {
            if( !visited[i][0] && board[i][0] == 1) {
                bfs(board,visited,i,0);
            }
        }
        for( int i = 0; i< m; i++) {
            if( !visited[i][n-1] && board[i][n-1] == 1) {
                bfs(board,visited,i,n-1);
            }
        }
        int count = 0;
        for( int i = 0; i< m; i++) {
            for( int j = 0; j< n; j++) {
                if( board[i][j] == 1 && visited[i][j] == false) {
                    count++;
                }
            }
        }
        return count;
    }
};
