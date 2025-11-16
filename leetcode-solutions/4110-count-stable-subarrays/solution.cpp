class Solution {
public:
    vector<long long> countStableSubarrays(vector<int>& v, vector<vector<int>>& q) {
        int n=v.size();
        vector<int>mp(n);
        vector<pair<int,int>>x;
        int start=0,id=0;
        for (int i=1;i<n;i++) {
            if (v[i] < v[i-1]) {
                x.push_back({start, i-1});
                start=i;
                id++;
            }
            mp[i]=id;
        }
        x.push_back({start, n-1});
        int bs = x.size();
        vector<long long> ps(bs+1);
        for (int i=0; i < bs; i++) {
            long long s = x[i].second - x[i].first + 1;
            ps[i+1] = ps[i] + s * (s+1)/2;
        }
        vector<long long> ans;
        for (auto &q : q) {
            int l = q[0], r = q[1];
            int bl = mp[l], br = mp[r];
            if (bl == br) {
                long long s=r-l+1;
                ans.push_back(s*(s+1)/2);
                continue;
            }
            int left = x[bl].second;
            long long lcnt = left-l+1, a = lcnt*(lcnt+1)/2;
            
            int right = x[br].first;
            long long rcnt = r-right+1; a += rcnt*(rcnt+1)/2;
            
            if (br>bl+1) a += ps[br]-ps[bl+1];
            ans.push_back(a);
        }
        return ans;
    }
};
