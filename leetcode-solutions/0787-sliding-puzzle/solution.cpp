class Solution {
public:
    int gptSolution(vector<vector<int>>& board) {
        string target = "123450";
        string start = "";  
        
        // Convert board into string format
        for (auto row : board)
            for (int num : row)
                start += to_string(num);
        
        // Directions for moving: left, right, up, down
        vector<vector<int>> directions = {
            {1, 3},    // Position 0: can move right, down
            {0, 2, 4}, // Position 1: can move left, right, down
            {1, 5},    // Position 2: can move left, down
            {0, 4},    // Position 3: can move up, right
            {1, 3, 5}, // Position 4: can move left, up, right
            {2, 4}     // Position 5: can move left, up
        };
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push({start, 0});  // (current state, move count)
        visited.insert(start);
        while (!q.empty()) {
            auto [cur, moves] = q.front();
            q.pop();
            if (cur == target) return moves;
            int zeroIndex = cur.find('0');
            
            for (int nextPos : directions[zeroIndex]) {
                string next = cur;
                swap(next[zeroIndex], next[nextPos]);
                if (!visited.count(next)) {
                    visited.insert(next);
                    q.push({next, moves + 1});
                }
            }
        }
        return -1;
    }
    
    int mySolution(vector<vector<int>>& board) {
        set<vector<vector<int>>>vis;
        queue<vector<vector<int>>>q;
        vector<vector<int>>ans = {{1,2,3},{4,5,0}};
        q.push(board);
        vis.insert(board);
        int swaps = 0;
        vector<pair<int,int>>directions = {{0,-1},{1,0},{0,1},{-1,0}};
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto temp = q.front();
                q.pop();
                if(temp == ans)return swaps;
                int row,col;
                for(int i= 0; i< 2; i++) {
                    for(int j= 0; j< 3; j++) {
                        if(temp[i][j] == 0) {
                            row = i;
                            col = j;
                        }
                    }
                }
                for(auto [dx,dy]: directions) {
                    int nr = row + dx;
                    int nc = col + dy;
                    
                    if( nr >= 0 && nr < 2 && nc >= 0 && nc < 3 ) {
                        swap(temp[row][col],temp[nr][nc]);
                        if(vis.find(temp) == vis.end()) {
                            q.push(temp);
                            vis.insert(temp);
                        }
                        swap(temp[row][col],temp[nr][nc]);
                    }
                }

            }
            swaps++;
        }
        return -1;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        return mySolution(board);
    }
};
