class Solution {
public:
    int numberOfSubstrings(string s) {
        // Array to keep track of the last seen positions of characters 'a', 'b', and 'c'
        int lastSeen[3] = {-1, -1, -1};  
        int ans = 0; // Variable to store the total count of valid substrings
        // Iterate through the string
        for (int i = 0; i < s.size(); i++) {
            // Update the last seen position for the current character
            lastSeen[s[i] - 'a'] = i;
            // Check if all three characters ('a', 'b', 'c') have been seen
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                // Find the earliest position of the three characters
                int earliest = min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
                // Add to the count all substrings starting from the earliest position to the current position
                // +1 accounts for the current substring that ends at 'i'
                ans += 1 + earliest;
            }
        }

        return ans; // Return the total count of substrings containing 'a', 'b', and 'c'
    }
};

