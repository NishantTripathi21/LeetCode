class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Floyd Warshal Algorithm
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
		for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
			dist[u][v] = wt;
			dist[v][u] = wt;
		}
        for (int i = 0; i < n; i++) dist[i][i] = 0;

        for (int via = 0; via < n; via++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (dist[i][via] == INT_MAX || dist[via][j] == INT_MAX)continue;
					dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
				}
			}
		}

        int cntCity = n; // keeps track of minimum cities that can be reached
		int cityNo = -1; // store ans
		for (int city = 0; city < n; city++) {
			int cnt = 0; // counts how many other cities can be reached from a city, under threshold constraint
			for (int adjCity = 0; adjCity < n; adjCity++) {
				if (dist[city][adjCity] <= distanceThreshold){
                    cnt++;
                }	
			}
            // if cities that can be reached is less than or equal to minimum number of cities 
			if (cnt <= cntCity) {
				cntCity = cnt;
				cityNo = city;
			}
		}
		return cityNo;
    }
};
