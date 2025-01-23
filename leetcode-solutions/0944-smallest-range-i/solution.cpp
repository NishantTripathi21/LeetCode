class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int minVal = nums[0];
        int maxVal = nums[nums.size() - 1];
        
        int newMin = minVal + k;
        int newMax = maxVal - k;

        return max(0, newMax - newMin);
    }
};
