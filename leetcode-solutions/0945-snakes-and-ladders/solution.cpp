class Solution {
public:
    int n;
    pair<int, int> getCoord(int s) {
        int row = n-1-(s-1)/n;
        
        int col = (s-1)%n;
        
        if((n%2==1 && row%2==1)||(n%2==0 && row%2==0))
            col = n-1-col;
        
        return make_pair(row, col);
    } 
    int bfs(vector<vector<int>>& board) {
        n = board.size();
        int steps = 0;
        queue<pair<int,int>> que;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[n-1][0] = true;
        que.push({1,0});       
        while(!que.empty()) {
            int N = que.size();
                auto [x,steps] = que.front();
                que.pop();
                if(x == n*n)
                    return steps;
                for(int k = 1; k<=6; k++) {
                    if(x+k > n*n)
                        break;
                    pair<int, int> coord = getCoord(x+k);
                    int r = coord.first;
                    int c = coord.second;
                    if(visited[r][c] == true)
                        continue;
                    visited[r][c] = true;
                    if(board[r][c] == -1)
                        que.push({k+x,steps+1});
                    else {
                        que.push({board[r][c],steps+1});
                    }
                }
            //steps++;
        }
        
        return -1;

    }
    int snakesAndLadders(vector<vector<int>>& board) {
        return bfs(board);
    }
};
