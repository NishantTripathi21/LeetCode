class Solution {
public:
    void bfs(int src,unordered_map<int,vector<int>>& adjList , vector<bool>& visited ) {
        queue<int>q;
        visited[src] = true;
        q.push(src);
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            for( auto i: adjList[top]) {
                if(!visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    void dfs(int src,unordered_map<int,vector<int>>& adjList , vector<bool>& visited) {
        visited[src] = true;
        for( auto i: adjList[src]) {
            if(!visited[i]) {
                dfs(i,adjList,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // make adjecency list
        unordered_map<int,vector<int>> adjList;
        int n = isConnected.size();
        
        for( int i= 0; i< n; i++) {
            for( int j=i+1; j< n; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int count = 0;
        vector<bool> visited(n+1,0);
        for( int i= 0; i<n; i++) {
            if( !visited[i])  {
                bfs(i,adjList,visited);
                count++;
            }
        }
        return count;

    }
};
