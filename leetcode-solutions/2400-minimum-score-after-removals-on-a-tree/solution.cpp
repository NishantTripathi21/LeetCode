
class Solution {
public:
    vector<vector<int>> tree;
    vector<int> in, out, subXOR;
    int timer = 0;

    void dfs(int node, int parent, const vector<int>& nums) {
        in[node] = timer++;
        subXOR[node] = nums[node];

        for (int neighbor : tree[node]) {
            if (neighbor == parent) continue;
            dfs(neighbor, node, nums);
            subXOR[node] ^= subXOR[neighbor];
        }

        out[node] = timer++;
    }

    bool isAncestor(int u, int v) {
        return in[u] <= in[v] && out[u] >= out[v];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        tree.assign(n, {});
        in.assign(n, 0);
        out.assign(n, 0);
        subXOR.assign(n, 0);

        // Build tree
        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        // DFS to compute subtree XORs
        dfs(0, -1, nums);

        int totalXOR = subXOR[0];
        int minScore = INT_MAX;

        // Try all pairs of edges: simulate removal via child node
        vector<pair<int, int>> edgeNodes; // store child node of each edge
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            if (in[a] > in[b]) swap(a, b); // make b the child
            edgeNodes.push_back({b, a});   // b is in subtree of a
        }

        int m = edges.size();
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                int u = edgeNodes[i].first;
                int v = edgeNodes[j].first;

                int x, y, z;
                if (isAncestor(u, v)) {
                    // v inside u's subtree
                    x = subXOR[v];
                    y = subXOR[u] ^ subXOR[v];
                    z = totalXOR ^ subXOR[u];
                }
                else if (isAncestor(v, u)) {
                    // u inside v's subtree
                    x = subXOR[u];
                    y = subXOR[v] ^ subXOR[u];
                    z = totalXOR ^ subXOR[v];
                }
                else {
                    // u and v are in different subtrees
                    x = subXOR[u];
                    y = subXOR[v];
                    z = totalXOR ^ x ^ y;
                }

                int maxVal = max({x, y, z});
                int minVal = min({x, y, z});
                minScore = min(minScore, maxVal - minVal);
            }
        }

        return minScore;
    }
};

