class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>minHeap;
        //{ time, (row,col)}
        int time = 0;
        int n = grid.size();
        minHeap.push({grid[0][0],{0,0}});
        int minTime = 0;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        while(!minHeap.empty()) {
            auto it= minHeap.top();
            int wt = it.first;
            int row= it.second.first;
            int col = it.second.second;
            minHeap.pop();
            vis[row][col] = true;
            
            time = max(time,wt);
            if( row== n-1 && col == n-1)return time;
            vector<pair<int,int>>direction= {{1,0},{0,1},{-1,0},{0,-1}};
            for(auto [dx,dy]: direction) {
                int nrow = row+dx;
                int ncol = col+dy;
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n) {
                    if(vis[nrow][ncol] == false){
                        minHeap.push({grid[nrow][ncol],{nrow,ncol}});
                    }
                } 
            }
        }
        return time;
    }
};
