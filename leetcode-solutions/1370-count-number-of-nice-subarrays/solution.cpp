class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0;// Left pointer of the sliding window
        int right = 0;// Right pointer of the sliding window
        int odds = 0;// Count of odd numbers in the current window
        int ans = 0;// Final count of nice subarrays
        int even_count = 0;// Count of consecutive even numbers before the current odd number

        // Iterate through the array using the right pointer
        while (right < nums.size()) {
            // If the current number is odd, increment the count of odd numbers
            if (nums[right] & 1) {
                odds++;
            }
            // Shrink the window from the left if:
            // - The count of odd numbers exceeds k, OR
            // - The current left number is not odd (to maintain a valid window)
            while ((odds > k || !(nums[left] & 1)) && left < right) {
                // If the leftmost number is odd, decrement the odd count
                if (nums[left] & 1) {
                    odds--;
                    even_count = 0;// Reset even count as we are excluding this odd number
                }
                else{
                    even_count++;// Increment even count as we exclude this even number
                }
                left++; // Move the left pointer forward
            }
            // If the window contains exactly k odd numbers:
            if (odds == k) {
                // Add 1 (for the current subarray) + the number of valid subarrays
                // starting with additional even numbers before the first odd in the window
                ans += 1 + even_count;
            }
            right++;
        }

        return ans;
    }
};

