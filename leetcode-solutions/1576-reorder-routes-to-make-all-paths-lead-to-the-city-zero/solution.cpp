class Solution {
public:
    void dfs(vector<vector<int>>& adj, set<pair<int,int>>& st, int node,int& ans, vector<int>& vis) {
        vis[node] = 1;
        for(auto it: adj[node]) {
            if(!vis[it]) {
                if(st.find({it,node}) == st.end())ans++;
                dfs(adj,st,it,ans,vis);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        set<pair<int,int>>st;
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(auto it: connections) {
            int u = it[0];
            int v = it[1];
            st.insert({u,v});
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans= 0;
        dfs(adj,st,0,ans,vis);
        return ans;
    }
};
