class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>adj(n+1);
        for(auto it: paths) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans(n, 0); 
        for (int i = 1; i <= n; i++) {
            unordered_set<int> used;
            for (int neighbor : adj[i]) {
                if (ans[neighbor - 1] > 0) {
                    used.insert(ans[neighbor - 1]);
                }
            }
            for (int flower = 1; flower <= 4; flower++) {
                if (used.find(flower) == used.end()) {
                    ans[i - 1] = flower;
                    break;
                }
            }
        }
        return ans;
    }
};
