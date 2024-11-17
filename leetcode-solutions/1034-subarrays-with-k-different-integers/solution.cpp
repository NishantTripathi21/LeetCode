/*
Logic:
The problem is to find the number of subarrays with exactly K distinct integers.
To achieve this:
1. We compute the count of subarrays with at most K distinct integers (`helper(nums, k)`).
2. Similarly, we compute the count of subarrays with at most (K + 1) distinct integers.
3. The difference between these two counts gives the number of subarrays with exactly K distinct integers:
   `subarraysWithKDistinct = helper(nums, k) - helper(nums, k + 1)`.
The `helper` function uses a two-pointer sliding window approach with an `unordered_map` to track the frequency of elements in the current window.
Steps in `helper` function:
- Use a `right` pointer to expand the window and an `unordered_map` to track element frequencies and positions.
- When the number of distinct elements exceeds K, move the left boundary (`mini`) to shrink the window until it satisfies the constraint (<= K distinct elements).
- Count valid subarrays whenever the window contains exactly K distinct elements.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    // Helper function to count subarrays with at most k distinct integers
    int helper(vector<int>& nums, int k) {
        unordered_map<int, int> mapping; // Tracks the last occurrence of each number
        int left = 0; // Tracks the left boundary of the sliding window
        int ans = 0; // Stores the count of valid subarrays
        int right = 0; // Right pointer for the sliding window

        while (right < nums.size()) {
            int element = nums[right];
            
            // If the element is already in the map, update its position
            if (mapping.find(element) != mapping.end()) {
                mapping[element] = right;

                // Recalculate the smallest index in the map
                left = INT_MAX;
                for (auto i : mapping) {
                    left = min(i.second, left);
                }
            }
            // Add the current element to the map
            mapping[element] = right;

            // If the number of distinct elements exceeds k, adjust the window
            if (mapping.size() > k) {
                int temp = nums[left]; // Element at the smallest index
                mapping.erase(temp); // Remove it from the map

                // Recalculate the smallest index in the map
                left = INT_MAX;
                for (auto i : mapping) {
                    left = min(i.second, left);
                }
            }

            // Count valid subarrays if the number of distinct elements equals k
            if (mapping.size() == k) {
                ans += 1 + left;
            }

            right++; // Expand the window
        }

        return ans; // Return the count of valid subarrays
    }

    // Main function to find subarrays with exactly K distinct integers
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans1 = helper(nums, k + 1); // Subarrays with at most (K + 1) distinct integers
        int ans2 = helper(nums, k); // Subarrays with at most K distinct integers
        return ans2 - ans1; // Return the difference
    }
};

