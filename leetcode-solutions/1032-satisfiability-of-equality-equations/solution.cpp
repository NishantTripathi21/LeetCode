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
    bool equationsPossible(vector<string>& equations) {
        disjoinSet ds(26);
        vector<pair<int,int>>unEqual;
        for(int i= 0; i< equations.size(); i++) {
            string str = equations[i];
            int u = str[0]-'a';
            int v = str[3]-'a';
            if(str[1] == '!') {
                unEqual.push_back({u,v});
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        for(auto [u,v]: unEqual) { 
            if(ds.findParent(u) == ds.findParent(v))return false;
        }
        return true;
    }
};
