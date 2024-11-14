class Solution {
public:
    int characterReplacement(string s, int k) {
        int right = 0; // Right pointer for the window
        int left = 0; // Left pointer for the window
        int hash[26] = {0};// Frequency array for characters 'A' to 'Z'
        int maxFreq = 0;// Tracks the highest frequency of any character in the current window
        int ans = 0;// Stores the maximum length of the valid window
        // Iterate over the string with the right pointer
        while (right < s.size()) {
            // Map the current character to an index in the hash array
            int index = s[right] - 'A';
            hash[index]++;// Increment frequency of the current character in the window
            maxFreq = max(maxFreq, hash[index]); // Update max frequency of any character in the current window
            // Check if the window is invalid (more than 'k' replacements )
            while((right - left + 1) - maxFreq > k){
                // Decrement the count of the character at the left pointer as we shrink the window
                hash[s[left] - 'A']--;
                left++;// Move the left pointer to shrink the window
            }
            // Calculate the maximum window length that satisfies the replacement condition
            ans = max(ans, right - left + 1);
            right++; // Expand the window by moving the right pointer
        }
        return ans; // Return the maximum length of a valid window
    }
};

