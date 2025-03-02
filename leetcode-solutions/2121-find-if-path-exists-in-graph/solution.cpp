class Solution {
public:
    int des = -1;
    bool ans = false;
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int node) {
        vis[node] = true;
        if(node == des){
            ans = true;
            return;
        }
        for(auto nbr: adj[node]) {
            if(!vis[nbr]) {
                dfs(adj,vis,nbr);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        des = destination;
        vector<vector<int>>adj(n);
        vector<bool>vis(n,false);
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(adj,vis,source);
        return ans;
    }
};
