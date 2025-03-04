class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> redAdj(n), blueAdj(n);
        
        for (auto edge : redEdges){
            redAdj[edge[0]].push_back(edge[1]);
        }    
        for (auto edge : blueEdges){
            blueAdj[edge[0]].push_back(edge[1]);
        }
        vector<int> result(n, -1);
        queue<pair<int, int>> q;  // {node, color} color: 0 = red, 1 = blue
        vector<vector<bool>> visited(n, vector<bool>(2, false));  // visited[node][color]

        q.push({0, 0}); // Red edge
        q.push({0, 1}); // Blue edge
        visited[0][0] = visited[0][1] = true;
        result[0] = 0;
        int dist = 0; 

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [node, color] = q.front();
                q.pop();
                if (result[node] == -1) {
                    result[node] = dist;
                }
                int nextColor = !color; 
                if(color == 0) {
                    for (int neighbor : blueAdj[node]) {
                        if (!visited[neighbor][nextColor]) {
                            visited[neighbor][nextColor] = true;
                            q.push({neighbor, nextColor});
                            
                        }
                    }
                }
                else{
                    for (int neighbor : redAdj[node]) {
                        if (!visited[neighbor][nextColor]) {
                            visited[neighbor][nextColor] = true;
                            q.push({neighbor, nextColor});
                            
                        }
                    }
                }
                
            }
            dist++;
        }

        return result;
    }
};
