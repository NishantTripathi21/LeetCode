class Solution {
public:
    class DSU {
    public:
        vector<int> parent, rank;
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        void unite(int x, int y) {
            int rx = find(x), ry = find(y);
            if (rx == ry) return;
            if (rank[rx] < rank[ry]) {
                parent[rx] = ry;
            } else if (rank[rx] > rank[ry]) {
                parent[ry] = rx;
            } else {
                parent[ry] = rx;
                rank[rx]++;
            }
        }
    };

    int components(int n, vector<vector<int>>& edges, int time) {
        DSU ds(n);
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            int t = it[2];
            if(t <= time) continue;
            ds.unite(u,v);
        }
        vector<bool> counted(n, false);
        int count = 0;
        for (int i = 0; i < n; ++i) {
            int root = ds.find(i);
            if (!counted[root]) {
                count++;
                counted[root] = true;
            }
        }
        return count;
    }
    int minTime(int n, vector<vector<int>>& edges, int k) {
        if (edges.empty()) return (n >= k) ? 0 : -1;

        // Extract and sort unique times
        set<int> timeSet;
        timeSet.insert(0);
        for (auto& edge : edges) timeSet.insert(edge[2]);
        vector<int> timeVals(timeSet.begin(), timeSet.end());

        int low = 0, high = timeVals.size() - 1, ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int t = timeVals[mid];
            int comps = components(n, edges, t);

            if (comps >= k) {
                ans = t;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
