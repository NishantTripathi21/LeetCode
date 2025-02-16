class Solution {
public:
    bool detectCycleUsingDFS(vector<vector<int>>& adj, vector<bool>& visited,int start,vector<int>pathVis) {
        visited[start] = true;
        pathVis[start] =true;
        for(auto it: adj[start]) {
            if( !visited[it] ) {
                if( detectCycleUsingDFS(adj,visited,it,pathVis))return true;
            }
            else if( pathVis[it]){
                return true;
            }
        }
        pathVis[start]= false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto i: prerequisites) {
            adj[i[0]].push_back(i[1]);
        }
        vector<bool>visited(numCourses,0);
        vector<int>pathVis(numCourses,0);
        for( int i = 0; i < numCourses; i++) {
            if( !visited[i]  && detectCycleUsingDFS(adj,visited,i,pathVis)) {
                return false;
            }
        }
        return true;
    }
};
