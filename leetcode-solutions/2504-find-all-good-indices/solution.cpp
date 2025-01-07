class Solution {
public:
    vector<int> method1(std::vector<int>& nums, int k) {
        // Vector to store whether an index from the right satisfies the conditions
        vector<int> fromRight(nums.size(), 0);
        int n = nums.size();
        int count = 0; // Counter to track non-decreasing subarray length to the right of a particular index

        // Loop to fill the `fromRight` array indicating if a subarray from `i` to `i+k` is non-decreasing
        for (int i = n - 1; i >= 0; i--) {
            // Mark the index `i` in `fromRight` if conditions are met
            if (i < n - k && count >= k - 1) {
                fromRight[i] = 1;
            }
            // Increment `count` if current element is less than or equal to the next element
            if (i < n - 1 && nums[i] <= nums[i + 1]) {
                count++;
            } 
            else {
                // Reset `count` if the condition is not met
                count = 0;
            }
        }

        count = 0; // Reset `count` for the calculating  non increasing subarray to the left of particular index
        vector<int> ans; // Vector to store the resulting good indices

        // Loop to find indices that are "good" based on conditions from left to right
        for (int i = 0; i < n; i++) {
            // Check if `i` is a good index based on conditions and fromRight array
            if (i >= k && count >= k - 1 && fromRight[i] == 1) {
                ans.push_back(i); // Add the good index to the result
            }
            // Increment `count` if current element is less than or equal to the previous element
            if (i > 0 && nums[i] <= nums[i - 1]) {
                count++;
            } else {
                // Reset `count` if the condition is not met
                count = 0;
            }
        }

        return ans; // Return the vector of good indices
    }
    vector<int> goodIndices(vector<int>& nums, int k) {
        return method1( nums,k);
    }
};
