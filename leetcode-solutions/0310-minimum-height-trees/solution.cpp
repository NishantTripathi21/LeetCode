class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        if(n == 1)return {0};
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>indegree(n);

        for(int i= 0; i< n; i++) { 
            for(auto it: adj[i]) {
                indegree[it]++;
            }
        }
        vector<int>result;
        queue<int>q;
        for(int i= 0; i< n; i++)  {
            if(indegree[i] == 1)q.push(i);
        }
        while(n > 2) {
            int size = q.size();
            n -= size;
            while(size--) {
                int node = q.front();
                q.pop();
                for(auto nbr: adj[node]) {
                    indegree[nbr]--;
                    if(indegree[nbr] == 1) {
                        q.push(nbr);
                    } 
                }
            }
        }

        while(!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};
