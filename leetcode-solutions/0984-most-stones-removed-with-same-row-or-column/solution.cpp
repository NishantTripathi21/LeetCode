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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int rows = 0;
        int cols = 0;
        for( auto it: stones) {
            rows= max(rows,it[0]);
            cols = max(cols,it[1]);
        }
        disjoinSet ds(rows+cols+1);
        unordered_map<int,int>mp;
        for(auto it:stones) {
            int rowNode = it[0];
            int colNode = it[1] + rows + 1;
            ds.unionBySize(rowNode,colNode);
            mp[rowNode] = 1;
            mp[colNode] = 1;
        }
        
        int count = 0;
        for(auto it: mp) {
            if(ds.findParent(it.first) == it.first)count++;
        }
        return n - count;
    }
};
