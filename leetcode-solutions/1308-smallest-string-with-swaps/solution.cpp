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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        disjoinSet ds(n);
        for(auto it: pairs) {
            int u = it[0];
            int v = it[1];
            ds.unionBySize(u,v);
        }

        unordered_map<int,vector<int>>mp;
        for(int i= 0; i< n; i++) {
            mp[ds.findParent(i)].push_back(i);
        }

        string ans = s;
        for(auto it: mp) {
            string str;
            auto indx = it.second;
            for(int i: indx) {
                str += s[i];
            }
            sort(str.begin(),str.end());

            for(int i= 0; i< indx.size(); i++) {
                ans[indx[i]] = str[i];
            }
        }
        return ans;
    }
};
