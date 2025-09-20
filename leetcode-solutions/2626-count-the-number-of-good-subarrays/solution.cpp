class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long count = 0;
        int n = nums.size();
        unordered_map<int,int>mp;
        int pairs = 0;
        int left = 0;
        int right = 0;
        while(right < nums.size()) {
            int val = nums[right];
            pairs += mp[val];
            mp[val]++;
            while(pairs >= k) {
                count += n - right;
                int rval = nums[left];
                mp[rval]--;
                pairs -= mp[rval];
                left++;
            }
            right++;
        }
        return count;
    }
};
