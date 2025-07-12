class Solution {
    public:
    class disjoinSet{
        public:
        vector<int>parent;
        disjoinSet(int N) {
            parent.resize(N+1);
            for(int i= 0; i< N+1; i++) {
                parent[i] = i;
            }
        }
        int findParent(int node) {
            if( parent[node] == node)return node;
            return parent[node]= findParent(parent[node]);
        }
        void unite(int u, int v) {
            int Uparent = findParent(u);
            int Vparent = findParent(v);
            if( Uparent == Vparent)return;
            parent[Uparent] = Vparent;
        }
    };
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        disjoinSet Ds(c+1);
        for(auto it: connections) {
            Ds.unite(it[0],it[1]);
        }
        unordered_map<int,set<int>>activeLineByOrder;
        vector<int>online(c+1,1);

        for(auto i= 1; i<= c; i++) {
            int root= Ds.findParent(i);
            activeLineByOrder[root].insert(i);
        }
        vector<int>ans;
        for(auto it: queries) {
            int code= it[0];
            int x = it[1];
            if(code == 2) {
                online[x] = 0; 
                int root = Ds.findParent(x);
                activeLineByOrder[root].erase(x);
            }
            else if( code == 1) {
                if(online[x] == 1) {
                    ans.push_back(x);
                }
                else{
                    int root = Ds.findParent(x);
                    if(activeLineByOrder[root].empty())ans.push_back(-1);
                    else
                        ans.push_back((*activeLineByOrder[root].begin()));
                }
            }
        }
        return ans;
    }
};
