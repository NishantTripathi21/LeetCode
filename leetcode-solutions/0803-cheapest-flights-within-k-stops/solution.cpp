class Solution {
public:
    int modifiedDijsktraUsingPQ( int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size();
        vector<pair<int,int>>price(n,{1e9,0}); // we keep track of price to reach a destination against number of stops
        vector<vector<pair<int,int>>>adj(n); 
        for(int i = 0; i< m; i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adj[u].push_back({v,wt});
        }
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>minHeap; //{cost,{city,stops}}
        minHeap.push({0,{src,0}});
        price[src] = {0,0};
        while(!minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            int cost = top.first;
            int city = top.second.first;
            int stops = top.second.second;
            price[city] = {cost,stops};
            // if destination is reached within minimum stops, return it- no need to check for cheaper price as first reached destination will be in minimum
            // cost becuase we have used minHeap which gives cheapest route first
            if( city == dst && stops <= k+1)return cost;

            for( auto [nextCity,fare]: adj[city]) {
                int newCost = fare + cost;
                int totalStops = stops + 1;
                // dont push any route which takes more than minimum destinations
                // compare price to reach that city and also compare stops to reach city
                if( totalStops <= k+1 && (price[nextCity].first > newCost || price[nextCity].second > totalStops)) {
                    minHeap.push({newCost,{nextCity,totalStops}});
                }
            }
        }
        return -1;
    }
    
    int modifiedDijkstraUsingQueue(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size();
        vector<vector<pair<int,int>>>adj(n); 
        for(int i = 0; i< m; i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adj[u].push_back({v,wt});
        }

        vector<int>dist(n,1e9);
        queue<pair<int,pair<int,int>>>q; //{stops,{city,cost}};
        q.push({0,{src,0}});
        dist[src] = 0;

        while(!q.empty()) {
            auto it = q.front();
            int stops = it.first;
            int city = it.second.first;
            int cost = it.second.second;
            q.pop();
            dist[city] = min(dist[city],cost);
            if( stops > k)continue;

            for( auto [nbr,wt]: adj[city]) {
                if( cost + wt < dist[nbr] && stops <= k) {
                    q.push({stops+1,{nbr,cost+wt}});
                }
            }
        } 
        return dist[dst] == 1e9 ? -1: dist[dst];
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        return modifiedDijkstraUsingQueue(n,flights,src,dst,k);
    }
};
