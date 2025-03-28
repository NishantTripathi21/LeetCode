class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int k = queries.size();
        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < k; i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());  
        
        vector<int> answer(k, 0);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        int count = 0; 
        
        for (auto [val, idx] : sortedQueries) {
            while (!pq.empty() && pq.top().first < val) {
                auto [val, cell] = pq.top(); pq.pop();
                int x = cell.first, y = cell.second;
                count++;
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny]) {
                        pq.push({grid[nx][ny], {nx, ny}});
                        visited[nx][ny] = true;
                    }
                }
            }
            answer[idx] = count;
        }
        
        return answer;
    }
};
