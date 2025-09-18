class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long ncount =  0;
        unordered_map<int,int>mp;
        for(int i= n-1;  i>= 0; i--) {
            int req = nums[i] - i;
            ncount += mp[req];
            mp[req]++;
        }
        long long totalPairs = 1ll*(n-1)*(n)/2;
        return totalPairs - ncount;
    }
};
