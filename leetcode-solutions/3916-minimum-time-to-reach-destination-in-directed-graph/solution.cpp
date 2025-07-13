class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<tuple<int, int, int>>> graph(n);
        for(auto it:edges) {
            int u = it[0];
            int v = it[1];
            int st = it[2];
            int ed = it[3];
            graph[u].push_back({v,st,ed});
        }
        vector<int>minTime(n,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>minHeap;
        minHeap.push({0,0});
        minTime[0] = 0;
        while(!minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            int time = top.first;
            int node = top.second;
            if( node == n-1) return time;
            if(time > minTime[node]) continue;
            for(auto& [v, st, ed] : graph[node]) {
                if (time > ed) continue;
                int waitTime = max(time, st); 
                if (waitTime + 1 < minTime[v]) {
                    minTime[v] = waitTime + 1;
                    minHeap.push({waitTime + 1, v});
                }
            }
        }
        return -1;
    }
};
