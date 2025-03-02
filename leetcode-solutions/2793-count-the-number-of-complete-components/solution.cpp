class Solution {
public:
    int nodeCount = 0;
    int edgeCount = 0;
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int node,int parent,set<pair<int,int>>& st) {
        vis[node] = true;
        nodeCount++;
        
        for(auto nbr: adj[node]) {
            if(!vis[nbr]) {
                st.insert({nbr,node});
                dfs(adj,vis,nbr,node,st);
            }
            else if( st.find({nbr,node}) == st.end() && st.find({node,nbr}) == st.end()) {
                st.insert({nbr,node});
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 0;
        vector<int>vis(n,0);
        for(int i= 0; i< n; i++) {
            if(!vis[i]) {
                set<pair<int,int>>st;
                dfs(adj,vis,i,-1,st);
                edgeCount = st.size();
                if((nodeCount*(nodeCount-1)/2) == edgeCount)ans++;
                nodeCount = 0;
                edgeCount = 0;
            }
        }
        return ans;
    }
};
