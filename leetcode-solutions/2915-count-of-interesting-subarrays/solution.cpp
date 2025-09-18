class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        long long ans = 0;
        long long prefix = 0;
        unordered_map<int, long long> freq;
        freq[0] = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] % modulo == k) {
                prefix++;
            }
            int need = (prefix - k) % modulo;
            if (need < 0) need += modulo;

            if (freq.find(need) != freq.end()) {
                ans += freq[need];
            }
            freq[prefix % modulo]++;
        }

        return ans;
    }
};
