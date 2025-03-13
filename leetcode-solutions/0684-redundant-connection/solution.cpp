class Solution {
public:
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int size = edges.size();
        disjoinSet ds(size+1);
        vector<int>ans;
        for(int i= 0; i< size; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            if(ds.findParent(u) == ds.findParent(v)){
                ans = {u,v};
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        return ans;
    }
};
