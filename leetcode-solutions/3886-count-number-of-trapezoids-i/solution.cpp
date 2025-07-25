class Solution {
public:
    long long combination(int n, int r= 2) {
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n - r)
            r = n - r;

        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res *= (n - r + i);
            res /= i;
        }
        return res;
    }
    int countTrapezoids(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1]; 
        });
        const int MOD = 1e9 + 7;
        unordered_map<int,int>verticalPoints;
        int ones = 0;
        for(auto it: points) {
            verticalPoints[it[1]]++;
        }
        int ans = 0;
        for(auto it: verticalPoints) {
            if(it.second == 1) ones++;
        }
        vector<int> pros;
        for (auto it : verticalPoints) {
            if (it.second == 1) continue;
            int combo = combination(it.second);
            pros.push_back(combo);
        }

        int totalCombination = 0;
        int sumSoFar = 0;
        for (int val : pros) {
            totalCombination = ((totalCombination + (1LL * val * sumSoFar) % MOD) % MOD);
            sumSoFar = (sumSoFar + val) % MOD;
        }
        return totalCombination;
    }
};
