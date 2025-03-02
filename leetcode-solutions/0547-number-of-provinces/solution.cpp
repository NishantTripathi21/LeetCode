class Solution {
    class disjoinSet{
        public:
        vector<int>parent,size;
        disjoinSet(int N) {
            parent.resize(N+1);
            size.resize(N+1,1);
            for(int i= 0; i< N+1; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findParent(int node) {
            if( parent[node] == node)return node;
            return parent[node]= findParent(parent[node]);
        }
        void unionBySize(int u, int v) {
            int Uparent = findParent(u);
            int Vparent = findParent(v);
            if( Uparent == Vparent)return;

            if( size[Uparent] < size[Vparent]) {
                parent[Uparent] = Vparent;
                size[Vparent] += size[Uparent];
            }
            else{
                parent[Vparent] = Uparent;
                size[Uparent] += size[Vparent];
            }
        }
    };

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
    int usingDSU(vector<vector<int>>& isConnected) {
        int n =  isConnected.size();
        disjoinSet ds(n);
        for(int i= 0; i< n; i++) {
            for(int j= 0; j< n; j++) {
                if(isConnected[i][j]) {
                    ds.unionBySize(i,j);
                }
            }
        }
        int count = 0;
        for(int i= 0; i< ds.parent.size(); i++) {
            if(ds.parent[i] == i)count++;
        }
        return count-1;
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
        return usingDSU(isConnected);

    }
};
