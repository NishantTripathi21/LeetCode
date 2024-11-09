class Solution {
public:
    long long sumofSubarrayMinimums(vector<int>& nums) {
        // Code is based on LeetCode problem 907 - Sum of Subarray Minimums
        
        // Stacks to keep track of indices of next and previous smaller elements
        stack<int> nextSmaller;
        stack<int> prevSmaller;
        
        // Vectors to store indices of next and previous smaller elements for each element in nums
        vector<int> nextSmallerIndex(nums.size(), nums.size()); // initialize to size, meaning no next smaller
        vector<int> prevSmallerIndex(nums.size(), -1); // initialize to -1, meaning no previous smaller
        
        // Calculate next smaller element index for each element
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!nextSmaller.empty() && nums[nextSmaller.top()] > nums[i]) {
                nextSmaller.pop(); // Remove elements from stack that are greater than nums[i]
            }
            if (!nextSmaller.empty()) {
                nextSmallerIndex[i] = nextSmaller.top(); // If stack isn't empty, set next smaller index
            }
            nextSmaller.push(i); // Push current index onto stack
        }

        // Output next smaller indices for debugging
        cout << "next smaller: ";
        for (int i : nextSmallerIndex) cout << i << " ";
        cout << endl;
        
        // Calculate previous smaller element index for each element
        for (int i = 0; i < nums.size(); i++) {
            while (!prevSmaller.empty() && nums[prevSmaller.top()] >= nums[i]) {
                prevSmaller.pop(); // Remove elements from stack that are greater or equal to nums[i]
            }
            if (!prevSmaller.empty()) {
                prevSmallerIndex[i] = prevSmaller.top(); // If stack isn't empty, set previous smaller index
            }
            prevSmaller.push(i); // Push current index onto stack
        }

        // Output previous smaller indices for debugging
        cout << "prev smaller: ";
        for (int i : prevSmallerIndex) cout << i << " ";
        cout << endl;

        // Calculate the sum of subarray minimums using nextSmallerIndex and prevSmallerIndex
        long long sum = 0;
        for (long long i = 0; i < nums.size(); i++) {
            sum += (nextSmallerIndex[i] - i) * (i - prevSmallerIndex[i]) * nums[i];
        }
        
        return sum;
    }

    long long sumOfSubarraymaximums(vector<int>& nums) {
        // Code is based on LeetCode problem 907, adapted for subarray maximums

        // Stacks to keep track of indices of next and previous greater elements
        stack<int> nextGreater;
        stack<int> prevGreater;
        
        // Vectors to store indices of next and previous greater elements for each element in nums
        vector<int> nextGreaterIndex(nums.size(), nums.size()); // initialize to size, meaning no next greater
        vector<int> prevGreaterIndex(nums.size(), -1); // initialize to -1, meaning no previous greater

        // Calculate previous greater element index for each element
        for (int i = 0; i < nums.size(); i++) {
            while (!prevGreater.empty() && nums[prevGreater.top()] < nums[i]) {
                prevGreater.pop(); // Remove elements from stack that are less than nums[i]
            }
            if (!prevGreater.empty()) {
                prevGreaterIndex[i] = prevGreater.top(); // If stack isn't empty, set previous greater index
            }
            prevGreater.push(i); // Push current index onto stack
        }

        // Output previous greater indices for debugging
        cout << "prev greater: ";
        for (int i : prevGreaterIndex) cout << i << " ";
        cout << endl;

        // Calculate next greater element index for each element
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!nextGreater.empty() && nums[nextGreater.top()] <= nums[i]) {
                nextGreater.pop(); // Remove elements from stack that are less than or equal to nums[i]
            }
            if (!nextGreater.empty()) {
                nextGreaterIndex[i] = nextGreater.top(); // If stack isn't empty, set next greater index
            }
            nextGreater.push(i); // Push current index onto stack
        }

        // Output next greater indices for debugging
        cout << "next greater: ";
        for (int i : nextGreaterIndex) cout << i << " ";
        cout << endl;

        // Calculate the sum of subarray maximums using nextGreaterIndex and prevGreaterIndex
        long long sum = 0;
        for (long long i = 0; i < nums.size(); i++) {
            sum += (nextGreaterIndex[i] - i) * (i - prevGreaterIndex[i]) * nums[i];
        }

        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        // Calculate the difference between the sum of subarray maximums and minimums
        // This will give the sum of all subarray ranges
        long long ans = sumOfSubarraymaximums(nums) - sumofSubarrayMinimums(nums);
        return ans;
    }
};

