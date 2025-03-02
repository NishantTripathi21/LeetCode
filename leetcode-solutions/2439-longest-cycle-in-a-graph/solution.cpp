class Solution {
public:
    int ans = -1;
    void dfs(vector<int>& adj, int node, vector<int>& vis, vector<int>& pathVis, int size) {
        vis[node] = 1;
        pathVis[node] = size;
        int nbr = adj[node];
            if( nbr != -1 && !vis[nbr]) {
                size++;
                dfs(adj,nbr,vis,pathVis,size);
            }
            else if(nbr != -1 &&  pathVis[nbr] != -1) {
                int cycleSize = size+1 - pathVis[nbr];
                ans = max(cycleSize,ans);
            }
        
        pathVis[node] = -1;
        size--;
    }
    int longestCycle(vector<int>& edges) {
        int n= edges.size();
        vector<int>vis(n,0);
        vector<int>pathVis(n,0);
        // vector<vector<int>>adj(n);
        for(int i= 0; i< n; i++) {
            if(!vis[i]) {
                dfs(edges,i,vis,pathVis,0);
            }
        }
        
        return ans;
    }
};
