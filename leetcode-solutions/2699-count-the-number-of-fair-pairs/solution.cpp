class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long count = 0;
        
        for (int i = 0; i < n - 1; ++i) {
            int left = i + 1;
            int right = n - 1;

            // Find the smallest index where nums[i] + nums[left] >= lower
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[i] + nums[mid] < lower) {
                    left = mid + 1;
                } 
                else{
                    right = mid - 1;
                }
            }
            int start = left;

            //find the largest index where nums[i] + nums[right] <= upper
            left = i + 1;
            right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[i] + nums[mid] > upper) {
                    right = mid - 1;
                } 
                else{
                    left = mid + 1;
                }
            }
            int end = right;

            // Count valid pairs
            if (start <= end) {
                count += (end - start + 1);
            }
        }
        
        return count;
    }
};
