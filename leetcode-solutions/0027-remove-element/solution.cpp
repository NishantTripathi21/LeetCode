class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
    
    // Loop through the array
    for (int j = 0; j < nums.size(); j++) {
        // If the current element is not equal to val
        if (nums[j] != val) {
            nums[i] = nums[j]; // Move it to index i
            i++; // Increment i
        }
    }
    
    return i; // i is the count of elements not equal to val
    }
};
