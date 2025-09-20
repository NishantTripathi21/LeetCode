class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // int left = 0;           // Left pointer of the sliding window
        // int right = 0;          // Right pointer of the sliding window
        // int ans = 0;            // Stores the total count of valid subarrays
        // int sum = 0;            // Tracks the sum of the current window
        // int count_zeros = 0;    // Tracks consecutive zeros in the window after shrinking
        // while (right < nums.size()) {
        //     // Expand the window by adding the current element to the sum
        //     sum += nums[right];
        //     // Shrink the window if the sum exceeds the goal or if there are extra leading zeros
        //     while ((sum > goal || nums[left] == 0) && left < right) {
        //         sum -= nums[left]; // Remove the leftmost element from the sum
        //         if (nums[left] == 0) {
        //             count_zeros++; // Increment zero count if left element is zero
        //         } 
        //         else{
        //             count_zeros = 0; // Reset zero count if a non-zero element is removed
        //         }
        //         left++; // Move the left pointer to shrink the window
        //     }
        //     // If the sum equals the goal, calculate the number of valid subarrays
        //     if (sum == goal) {
        //         ans += 1 + count_zeros; // Include the current window and subarrays formed by leading zeros
        //     }
        //     // Move the right pointer to expand the window
        //     right++;
        // }
        // return ans;
        return solve(nums,goal);
    }
    int solve(vector<int>&nums, int goal) {
        unordered_map<int,int>mp;
        int count = 0;
        int sum = 0;
        mp[0] = 1;
        for(int i= 0; i< nums.size(); i++) {
            sum += nums[i];
            int req = sum - goal;
            if(mp.find(req) != mp.end()) {
                count += mp[req];
            }
            mp[sum]++;
        }
        return count;
    }
};

