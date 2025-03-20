class Solution {
public:
    class disjoinSet{
        public:
        vector<int>parent,rank,size;
        disjoinSet(int N) {
            parent.resize(N+1);
            rank.resize(N+1,0);
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

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        disjoinSet ds(n+1);
        vector<int>temp(n,-1);
        for(int i= 0; i< edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            int uP = ds.findParent(u);
            int vP = ds.findParent(v);
            if( uP != vP) {
                temp[uP] &= temp[vP];
                ds.unionBySize(uP,vP);
            }
            temp[uP] &= wt;
            temp[vP] &= temp[uP];
        }
        vector<int>ans;
        for(auto it: query) {
            int u = it[0];
            int v = it[1];
            int up = ds.findParent(u);
            int vp = ds.findParent(v);
            if(u == v) {
                ans.push_back(0);
            }
            else if(up != vp) {
                ans.push_back(-1);
            }
            else ans.push_back(temp[up]);
        }
        return ans;
    }
};
