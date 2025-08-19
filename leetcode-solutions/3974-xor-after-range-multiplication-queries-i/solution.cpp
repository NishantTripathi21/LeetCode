class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto it: queries) {
            int l = it[0];
            int r = it[1];
            int k = it[2];
            int v = it[3];
            int idx = l;
            while(idx <= r) {
                nums[idx] = (1LL * nums[idx] * v) % 1000000007;
                idx += k;
            }
        }
        int xorSum  = 0;
        for(auto it: nums) {
            xorSum ^= it;
        }
        return xorSum;
    }
};
