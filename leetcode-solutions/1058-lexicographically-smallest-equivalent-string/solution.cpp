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

        void unionBySize(int u, int v) {
            int Uparent = findParent(u);
            int Vparent = findParent(v);
            if( Uparent == Vparent)return;

            if( Uparent < Vparent) {
                parent[Vparent] = Uparent;
            }
            else{
                parent[Uparent] = Vparent;
            }
        }
    };

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        disjoinSet ds(26);
        for(int i= 0; i< s1.size(); i++) {
            int u = s1[i] - 'a';
            int v = s2[i] - 'a';
            ds.unionBySize(u,v);
        }
        string ans ="";
        for(int i= 0; i< baseStr.size(); i++) {
            char ch = ds.findParent(baseStr[i]-'a') + 'a';
            ans.push_back(ch);
        }
        return ans;
    }
};
