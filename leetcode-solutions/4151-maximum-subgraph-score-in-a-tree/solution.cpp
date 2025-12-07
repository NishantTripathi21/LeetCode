class Solution {
public:
    vector<vector<int>> tree;
    vector<int> value, gain, finalScore;
    void DFS(int node, int parent) {
        gain[node] = value[node];
        for (int child : tree[node]) {
            if (child == parent) continue;
            DFS(child, node);
            if (gain[child] > 0) {
                gain[node] += gain[child];
            }
        }
    }
    void dfs2(int node, int parent) {
        finalScore[node] = gain[node];
        for (int child : tree[node]) {
            if (child == parent) continue;
            int a = gain[node];
            int b = gain[child];
            if(gain[child] > 0)gain[node] -= gain[child];
            if(gain[node] > 0)gain[child] += gain[node];
            dfs2(child, node);
            gain[node] = a;
            gain[child] = b;
        }
    }
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        tree.resize(n);
        gain.resize(n);
        value.resize(n);
        finalScore.resize(n);
        for(int i = 0; i < n; i++) {
            value[i] = (good[i] == 1 ? 1 : -1);
        }
        for (auto e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        DFS(0, -1);
        dfs2(0, -1);
        return finalScore;
    }
};
