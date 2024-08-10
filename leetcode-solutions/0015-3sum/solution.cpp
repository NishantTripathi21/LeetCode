class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        
        // Step 1: Sort the array to make it easier to skip duplicates and use two pointers
        std::sort(nums.begin(), nums.end());
        
        // Step 2: Iterate through the array with the first pointer `i`
        for (int i = 0; i < nums.size(); ++i) {
            // Skip duplicate values for `i`
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = nums.size() - 1;
            
            // Step 3: Use the two-pointer technique to find the remaining two numbers
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    // Found a triplet that sums to zero
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicate values for `left` and `right`
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    // Move the pointers inward
                    left++;
                    right--;
                } else if (sum < 0) {
                    // If the sum is less than zero, move the left pointer to the right to increase the sum
                    left++;
                } else {
                    // If the sum is greater than zero, move the right pointer to the left to decrease the sum
                    right--;
                }
            }
        }
        
        return result;
    }
};
