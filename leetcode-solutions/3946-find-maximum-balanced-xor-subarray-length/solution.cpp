class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        unordered_map<long long, unordered_map<int, int>> mp;
        int n = nums.size();
        int b = 0;    
        int xr = 0;          
        int ans = 0;
        mp[0][0] = -1;
    
        for (int i = 0; i < n; i++) {
            xr ^= nums[i];
            b += (!(nums[i] & 1) ? 1 : -1);
            if(mp[xr].count(b)) {
                ans = max(ans, i - mp[xr][b]);
            }
            else {
                mp[xr][b] = i;
            }
        }
        return ans;
    }
};
