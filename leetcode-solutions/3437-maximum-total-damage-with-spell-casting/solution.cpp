class Solution {
public:
    vector<long long>dp;
    long long solve(vector<pair<int,int>>& pp, int index) {
        if(index >= pp.size())return 0;
        if(dp[index] != -1)return dp[index];
        long long np = solve(pp, index+1);

        int j = index + 1;
        while(j < pp.size() && pp[j].first <= pp[index].first + 2) {
            j++;
        }
        long long p = 1ll* pp[index].second * pp[index].first + (long long)solve(pp,j);

        return dp[index] = max(p,np);
    }
    long long maximumTotalDamage(vector<int>& power) {
        vector<pair<int,int>>pp; //paired powers
        unordered_map<int,int>mp;
        int n = power.size();
        dp.resize(n+2,-1);
        for(int i: power) {
            mp[i]++;
        }
        for(auto it: mp) {
            pp.push_back({it.first,it.second});
        }
        sort(pp.begin(),pp.end());
        return solve(pp,0);
    }
};
