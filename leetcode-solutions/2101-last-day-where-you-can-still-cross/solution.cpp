class Solution {
public:
    int row, col;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    bool canCross(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for (int c = 0; c < col; c++) {
            if (grid[0][c] == 0) {
                q.push({0, c});
                visited[0][c] = true;
            }
        }
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            if(r == row - 1) return true;
            for (auto [dx, dy] : directions) {
                int nr = r + dx, nc = c + dy;
                if (nr >= 0 && nr < row && nc >= 0 && nc < col && !visited[nr][nc] && grid[nr][nc] == 0){
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        this->row = row;
        this->col = col;
        int left = 0;
        int right = row* col;
        int ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            vector<vector<int>> grid(row, vector<int>(col, 0));
            for (int i = 0; i < mid; i++) {
                grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
            }

            if (canCross(grid)) {
                ans = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return ans;
    }
};
