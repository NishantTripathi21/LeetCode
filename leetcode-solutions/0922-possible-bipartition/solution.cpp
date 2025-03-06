class Solution {
public:
    bool bipartiteCheck(vector<vector<int>>& adj, int start,vector<int>& color) {
        color[start] = 1;
        queue<int>q;
        q.push(start);
        while(!q.empty()) {
            int frnd = q.front();
            q.pop();
            for(int enmy: adj[frnd]) {
                if(color[enmy] == -1) {
                    color[enmy] = !color[frnd];
                    q.push(enmy);
                }
                else if( color[enmy] == color[frnd]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>color(n+1,-1);
        vector<vector<int>>adj(n+1);
        for(auto it: dislikes) {
            int frnd1 = it[0];
            int frnd2 = it[1];
            adj[frnd1].push_back(frnd2);
            adj[frnd2].push_back(frnd1);
        }
        
        for(int i= 1; i< n+1; i++) {
            if(color[i] == -1 && bipartiteCheck(adj,i,color) == false)return false;
        }

        return true;
    }
};
