class Solution {
public:
    int n;
    unordered_map<int,pair<int,int>>track;
    pair<int,int> dfs(vector<vector<int>>& adj,int node, vector<int>& vis, vector<int>& ans, vector<int>& quiet) {
        vis[node] = 1;
        pair<int,int> pr = {quiet[node], node};

        for (int nbr : adj[node]) {
            if (!vis[nbr]) {
                auto nbrPr = dfs(adj, nbr, vis, ans, quiet);
                if (nbrPr.first < pr.first) {
                    pr = nbrPr;
                }
            }
            if(track.find(nbr) != track.end()) {
                if(track[nbr].first < pr.first) {
                    pr = track[nbr];
                }
            }
        }
        track[node] = pr;
        ans[node] = pr.second;
        return pr;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        this->n = quiet.size();
        vector<vector<int>>adj(n);
        for(auto it: richer) {
            int v = it[1];
            int u = it[0];
            adj[v].push_back(u);
        }

        vector<int>ans(n,0);
        vector<int>vis(n,0);
        for(int i= 0; i< n; i++) {
            if(!vis[i]) {
                dfs(adj,i,vis,ans,quiet);
            }
        }
        return ans;
    }
};
