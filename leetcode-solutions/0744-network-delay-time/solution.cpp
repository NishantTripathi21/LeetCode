class Solution {
public:
    int usingDijkstra( vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1); //{u,{v,wt}};
        for(int i = 0; i< times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];
            adj[u].push_back({v,wt}); 
        }
        
        vector<int>track(n+1,1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>minHeap; //{time,node}
        minHeap.push({0,k});
        track[k] = 0;
        while(!minHeap.empty()) {
            auto [time,node] = minHeap.top();
            minHeap.pop();
            track[node] = min(track[node],time);
            for( auto [nbr,wt]: adj[node]) {
                if( track[nbr] > wt+ time) {
                    minHeap.push({time+wt,nbr});
                }
            }
        }
        int minTime = INT_MIN;
        for( int i = 1; i< n+1; i++) {
            minTime = max(track[i],minTime);
        }
        return minTime == 1e9 ? -1 : minTime;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        return usingDijkstra(times,n,k);
    }
};
