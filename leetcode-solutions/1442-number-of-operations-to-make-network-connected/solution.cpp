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
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjoinSet ds(n);
        int extraEdges = 0;
        for( int i= 0; i< connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            if( ds.findParent(u) == ds.findParent(v)){
                extraEdges++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        int numberOfConnectedComponents = 0;
        for(int i= 0; i< n; i++) {
            if(ds.parent[i] == i)numberOfConnectedComponents++;
        }
        int ans = numberOfConnectedComponents - 1;
        if(extraEdges < ans)return -1;
        return ans;
    }
};
