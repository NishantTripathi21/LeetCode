class Solution {
public:
    class DSU {
    public:
        vector<int> parent;
        DSU(int n) {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
        }
        
        int find(int x) {
            if (parent[x] != x) 
                parent[x] = find(parent[x]);
            return parent[x];
        }
        
        void unite(int x, int y) {
            parent[find(x)] = find(y);
        }
    };
    int removeEdges(int n, vector<vector<int>>& edges, int wt) {
        DSU ds(n);
        for(auto it: edges) {
            if(it[2] <= wt) {
                ds.unite(it[0],it[1]);
            }
        }
        unordered_set<int>st;
        for(int i= 0; i< n; i++) {
            st.insert(ds.find(i));
        }
        return st.size();
    }
    int minCost(int n, vector<vector<int>>& edges, int k) {
        int maxWt = INT_MIN;
        for(auto it: edges) {
            maxWt = max(maxWt,it[2]);
        }
        int low = 0;
        int high = maxWt;
        int ans = 0;
        while(low <= high) {
            int mid = (low + high) / 2;
            int comps = removeEdges(n,edges, mid);
            if( comps <= k) {
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
