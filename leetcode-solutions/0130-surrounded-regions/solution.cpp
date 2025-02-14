class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<bool>>&visited, int x, int y) {
        visited[x][y] = true;
        int n = board[0].size();
        int m = board.size();
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for( auto [dx,dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && visited[nx][ny] == false && board[nx][ny] == 'O') {
                dfs(board,visited,nx,ny);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
       int n = board[0].size();
       int m = board.size();
        vector<vector<bool>>visited(m, vector<bool>(n,false));
        for( int i = 0; i< n; i++) {
            if( !visited[0][i] && board[0][i] == 'O') {
                dfs(board,visited,0,i);
            }
        }
        for( int i = 0; i< n; i++) {
            if( !visited[m-1][i] && board[m-1][i] == 'O') {
                dfs(board,visited,m-1,i);
            }
        }
        for( int i = 0; i< m; i++) {
            if( !visited[i][0] && board[i][0] == 'O') {
                dfs(board,visited,i,0);
            }
        }
        for( int i = 0; i< m; i++) {
            if( !visited[i][n-1] && board[i][n-1] == 'O') {
                dfs(board,visited,i,n-1);
            }
        }
        for( int i = 0; i< m; i++) {
            for( int j = 0; j< n; j++) {
                if( board[i][j] == 'O' && visited[i][j] == false) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
