class Solution {
public:
    int n;
    class disjoinSet{
        public:
        vector<int>parent,size;
        disjoinSet(int N) {
            parent.resize(N+1);
            size.resize(N+1,1);
            for(int i= 0; i< N+1; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findParent(int node) {
            if( parent[node] == node)return node;
            return parent[node]= findParent(parent[node]);
        }
        
        void unionBySize(int u, int v) {
            int Uparent = findParent(u);
            int Vparent = findParent(v);
            if( Uparent == Vparent)return;

            if( size[Uparent] < size[Vparent]) {
                parent[Uparent] = Vparent;
                size[Vparent] += size[Uparent];
            }
            else{
                parent[Vparent] = Uparent;
                size[Uparent] += size[Vparent];
            }
        }
    };
    bool isValid(int newr, int newc, int n) {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        disjoinSet ds(n*n + 1);
        for (int row = 0; row < n ; row++) {
            for (int col = 0; col < n ; col++) {
                if (grid[row][col] == 0) continue;
                vector<pair<int,int>>direction = {{0,1},{1,0},{-1,0},{0,-1}};
                for (auto [dx,dy]: direction) {
                    int newr = row + dx;
                    int newc = col + dy;
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;
                vector<pair<int,int>>direction = {{0,1},{1,0},{-1,0},{0,-1}};
                set<int> components;
                for (auto [dx,dy]: direction) {
                    int newr = row + dx;
                    int newc = col + dy;
                    if (isValid(newr, newc, n)) {
                        if (grid[newr][newc] == 1) {
                            components.insert(ds.findParent(newr * n + newc));
                        }
                    }
                }
                int sizeTotal = 0;
                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal + 1);
            }
        }
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            mx = max(mx, ds.size[ds.findParent(cellNo)]);
        }
        return mx;
    }
};
