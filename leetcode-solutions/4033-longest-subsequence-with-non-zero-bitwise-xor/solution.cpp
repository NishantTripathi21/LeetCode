class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xorv = 0;
        bool flag = false;
        int prev = 0 ;
        for(auto i:nums) {
            xorv ^= i;
            if(i != prev) {
                flag = true;
            }
        }
        if(!flag)return 0;
        return xorv == 0 ? n-1 : n;
    }
};
