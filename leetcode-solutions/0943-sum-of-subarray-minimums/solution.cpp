class Solution {
public:
    long long mod = 1e9 + 7; // Large prime modulus for avoiding overflow

    // Helper function to calculate sum of minimums of all subarrays
    int usingStack(vector<int>& arr) {
        // The approach is based on finding the next and previous smaller elements for each element in `arr`
        // Each element `arr[i]` can be the smallest element in several subarrays
        stack<int> nextSmaller;  // Stack to keep track of next smaller elements
        stack<int> prevSmaller;  // Stack to keep track of previous smaller elements
        // Initializing vectors for next and previous smaller indices with default values
        vector<int> nextSmallerIndex(arr.size(), arr.size()); // Initialize with arr.size() for elements with no next smaller
        vector<int> prevSmallerIndex(arr.size(), -1); // Initialize with -1 for elements with no previous smaller

        // Find next smaller element indices for each element
        for (int i = arr.size() - 1; i >= 0; i--) {
            // Pop elements from the stack until the top element is smaller than `arr[i]`
            while (!nextSmaller.empty() && arr[nextSmaller.top()] >= arr[i]) {
                nextSmaller.pop();
            }
            // If stack is not empty, top element is the index of next smaller element
            if (!nextSmaller.empty()) {
                nextSmallerIndex[i] = nextSmaller.top();
            }
            // Push the current index onto the stack
            nextSmaller.push(i);
        }

        // Debug output: print next smaller indices
        cout << "Next smaller indices: ";
        for (auto i : nextSmallerIndex) cout << i << " ";
        cout << endl;

        // Find previous smaller element indices for each element
        for (int i = 0; i < arr.size(); i++) {
            // Pop elements from the stack until the top element is smaller than `arr[i]`--here equal is not used to 
            // avoid duplicacy in subarrays--- dry run on testcase [1,3,3]- with equal to [3,3] aubarray gets counted
            //two times . try on testcase [71,55,82,55] without using equal to sign in both loops
            // one loop either nextsmaller or prevSmaller have to use equal to sign
            while (!prevSmaller.empty() && arr[prevSmaller.top()] > arr[i]) {
                prevSmaller.pop();
            }
            // If stack is not empty, top element is the index of previous smaller element
            if (!prevSmaller.empty()) {
                prevSmallerIndex[i] = prevSmaller.top();
            } else {
                // Otherwise, there is no previous smaller, so keep -1
                prevSmallerIndex[i] = -1;
            }
            // Push the current index onto the stack
            prevSmaller.push(i);
        }

        // Debug output: print previous smaller indices
        cout << "Previous smaller indices: ";
        for (auto i : prevSmallerIndex) cout << i << " ";
        cout << endl;

        // Calculate total sum of minimums for all subarrays
        int totalSum = 0;
        for (int i = 0; i < arr.size(); i++) {
            // Calculate the contribution of `arr[i]` in the subarrays where it is the minimum
            totalSum = (totalSum + (((nextSmallerIndex[i] - i)%mod) * ((i - prevSmallerIndex[i]))%mod * arr[i]) % mod) % mod;
        }
        
        // Return the result modulo mod to avoid overflow
        return totalSum % mod;
    }

    // Main function to calculate the sum of minimums of all subarrays
    int sumSubarrayMins(vector<int>& arr) {
        return usingStack(arr);
    }
};

