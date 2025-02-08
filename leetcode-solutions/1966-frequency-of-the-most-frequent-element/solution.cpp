class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long left = 0, totalOperations = 0, maxFreq = 0;
        for(long right = 0; right < nums.size(); right++) {
            if( right > 0) totalOperations += (nums[right] - nums[right - 1]) * (right - left);
            while(totalOperations > k) {
                totalOperations -= (nums[right] - nums[left]);
                left++;
            }
            maxFreq = max(maxFreq, right - left + 1);

        }

        return maxFreq;
    }
};
