class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int start, stack<int>& st ) {
        // it cant detect cycle, but can provide correct topoSort if there is no cycle- PathVisit method(track of current path)
        // can be added in this fuction for correct output
        vis[start] = true;
        for( auto  it: adj[start]) {
            if( !vis[it]){
                dfs(adj,vis,it,st);
            }
        }
        //cout<<" start: "<<start<<endl;
        st.push(start);
    }

    vector<int> helperUsingDFS( vector<vector<int>>& adj, int numCourses){
        stack<int>st;
        vector<bool>vis(numCourses,0);
        for( int i= 0; i< numCourses; i++) {
            if(!vis[i]) {
                dfs(adj,vis,i,st);
            }
        }
        vector<int>ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if( ans.size() == numCourses)return ans;
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // topoSort- DFS for topoSort cant detect cycle. we need to use BFS(Kahn algo)
        vector<vector<int>>adj(numCourses);
        for(auto i: prerequisites) {
            adj[i[0]].push_back(i[1]);
        }
        //return helperUsingDFS(adj,numCourses);

        // using kahn Algo
        
        vector<int>indegree(numCourses,0);
        for(auto i = 0; i< numCourses; i++) {
            for( auto it: adj[i]) {
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i = 0; i< numCourses; i++) {
            if(indegree[i] ==0) {
                q.push(i);
            }
        }
        vector<int>ans;
        while( !q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]) {
                indegree[it]--;
                if( indegree[it] == 0){
                    q.push(it);
                }
            }

        }
        reverse(ans.begin(),ans.end());
        if( ans.size() < numCourses)return {};
        return ans;
    }
};
