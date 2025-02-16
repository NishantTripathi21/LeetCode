class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, vector<int>& pathVis, vector<int>& check, int node) {
        visited[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        for( auto it: graph[node]) {
            if(!visited[it]) {
                if(dfs(graph,visited,pathVis, check,it))return true;
            }
            else if( pathVis[it]) {
                //cycle detected
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        int v = graph.size();
        vector<int>visited(v,0);
        vector<int>pathVis(v,0);
        vector<int>check(v,0);
        for( int i= 0; i< v; i++) {
            if( !visited[i] ) {
                dfs(graph,visited,pathVis,check,i);
            }
        }

        for( int i= 0; i< v; i++){
            if(check[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
