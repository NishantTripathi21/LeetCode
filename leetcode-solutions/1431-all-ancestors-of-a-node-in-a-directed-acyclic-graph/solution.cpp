class Solution {
public:
    void dfs(vector<vector<int>>& adj, int ancestor,int node, vector<vector<int>>& ans) {
        for(int nbr: adj[node]) {
            if(ans[nbr].empty() || ans[nbr].back() != ancestor) {
                ans[nbr].push_back(ancestor);
                dfs(adj,ancestor,nbr,ans);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        vector<vector<int>>ans(n);
        for(int i= 0; i< n; i++) {
            dfs(adj,i,i,ans);
        }
        return ans;
        
    }
};
