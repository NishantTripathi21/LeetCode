class Solution {
public:
    struct CompareFourth {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return a[3] > b[3];
        }
    };
    int usingdijkstrTemplate(int m, int n, vector<vector<int>>& waitCost) {
        priority_queue<vector<int>, vector<vector<int>>, CompareFourth> minHeap;
        minHeap.push({1,0,0,1});
        vector<vector<vector<long long>>> visited(m, vector<vector<long long>>(n, vector<long long>(2, LLONG_MAX)));
        visited[0][0][1] = (0 + 1) * (0 + 1);
        while (!minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            int cost = top[3];
            int row = top[1];
            int col = top[2];
            int sec = top[0];
            //cout<<" second: "<<sec<<" row: "<<row<<" col: "<<col<<" cost: "<<cost<<endl;
            if( row == m-1 && col == n-1) return cost;
            if (cost > visited[row][col][sec & 1])continue;
            if(sec & 1) {
                for(auto [dx,dy]: directions) {
                    int nr = row + dx;
                    int nc = col + dy;
                    int nSec = sec + 1;
                    if(nr < m && nc < n) {
                        int nCost =  cost + (nr + 1) * (nc+1);
                        if(nCost < visited[nr][nc][nSec & 1]) {
                            visited[nr][nc][nSec&1]= nCost;
                            minHeap.push({nSec,nr,nc,nCost});
                        }
                    }
                }
            }
            else{
                long long waitFee = waitCost[row][col];
                int nSec = sec + 1;
                int newCost = cost + waitFee;
                if (newCost < visited[row][col][nSec & 1]) {
                    visited[row][col][nSec % 2] = newCost;
                    minHeap.push({nSec, row, col, newCost});
                }
            }
            
            
        }
        return 0 ;
    }
    vector<pair<int,int>> directions = {{1,0},{0,1}};
    int m, n;
    vector<vector<vector<long long>>> dp;
    
    long long usingRecDP(vector<vector<int>>& waitCost, int i, int j, int sec) {
        if (i >= m || j >= n) return LLONG_MAX;
        if (i == m-1 && j == n-1) return 0;

        int parity = sec % 2;
        if (dp[i][j][parity] != -1) return dp[i][j][parity];

        long long minCost = LLONG_MAX;

        if (parity == 1) {
            for (auto [dx, dy] : directions) {
                int ni = i + dx;
                int nj = j + dy;
                if (ni < m && nj < n) {
                    long long moveCost = (ni + 1LL) * (nj + 1LL);
                    long long totalCost = usingRecDP(waitCost, ni, nj, sec + 1);
                    if (totalCost != LLONG_MAX)
                        minCost = min(minCost, moveCost + totalCost);
                }
            }
        } else {
            long long waitFee = waitCost[i][j];
            long long totalCost = usingRecDP(waitCost, i, j, sec + 1);
            if (totalCost != LLONG_MAX)
                minCost = waitFee + totalCost;
        }

        return dp[i][j][parity] = minCost;
    }

    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        this->m = m;
        this->n = n;
        dp.assign(m, vector<vector<long long>>(n, vector<long long>(2, -1)));
        long long startCost = 1;
        long long restCost = usingRecDP(waitCost, 0, 0, 1);
        return startCost + restCost;
    }
};
