class Solution {
public:
    void bfs(queue<pair<int,int>> q, vector<vector<int>> &heights, vector<vector<int>> &vis, int delRow[], int delCol[]){
        int n=heights.size();
        int m=heights[0].size();

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            int height=heights[row][col];
            for(int i=0;i<4;i++){
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && heights[nrow][ncol]>=height){
                    vis[nrow][ncol]=1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //pacific-0 atlantic-1 both-2
        int n=heights.size();
        int m=heights[0].size();

        int delRow[]={-1, 0, 1, 0};
        int delCol[]={0, -1, 0, 1};
        vector<vector<int>> pacific(n, vector<int>(m,0));
        vector<vector<int>> atlantic(n, vector<int>(m,0));

        //0,1,2 r,c
        queue<pair<int,int>> pacificQueue;
        queue<pair<int, int>> atlanticQueue;
        for(int i=0;i<n;i++){
            pacific[i][0]=1;//left
            pacificQueue.push({i, 0});
            atlantic[i][m-1]=1;//right
            atlanticQueue.push({i, m-1});
        }
        for(int j=0;j<m;j++){
            pacific[0][j]=1;//top
            pacificQueue.push({0, j});
            atlantic[n-1][j]=1;//bottom
            atlanticQueue.push({n-1,j});        
        }

        bfs(pacificQueue, heights, pacific, delRow, delCol);
        bfs(atlanticQueue, heights, atlantic, delRow, delCol);

        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] &&atlantic[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
