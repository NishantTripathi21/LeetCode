class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();
        vector<long long>preSum(n+1,0);
        for(int i= 1; i<= n; i++) {
            preSum[i]= preSum[i-1]+ capacity[i-1];
        }

        long long ans = 0;
        unordered_map<long long, unordered_map<long long,int >>mp; // {num->{sum->count}}

        int right = 0;
        while(right < n) {
            long long val = capacity[right];
            int left = right - 2;
            if(right >= 2) {
                mp[capacity[left]][preSum[left] + capacity[left]]++;
                long long t1 = capacity[right];
                long long t2 = preSum[right];
                if(mp.count(t1) && mp[t1].count(t2-t1)) {
                    ans += mp[t1][t2-t1];
                }
            }
            right++;
        }
        return ans;
    }
};
