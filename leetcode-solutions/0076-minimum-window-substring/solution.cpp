class Solution {
public:
    string minWindow(string s, string t) {
        // If t is longer than s, it's impossible to find a valid substring
        if (t.size() > s.size()) return ""; 
        // Frequency map to count characters in t
        vector<int> hash(256, 0);
        for (char c : t) {
            hash[c]++;
        }
        int left = 0, right = 0;// Pointers to define the sliding window
        int count = 0;// Count of characters matched from t
        int ans = INT_MAX;// Length of the smallest window found
        int sIndex = -1;// Starting index of the smallest window
        int m = t.size();// Length of string t

        while(right < s.size()){
            // If the current character is in t and is still required
            if(hash[s[right]] > 0){
                count++;
            }
            // Decrease the frequency of the character in the hash map
            hash[s[right]]--;
            // Shrink the window from the left while all characters are matched
            while(count == m){
                // Check if the current window is smaller than the previously found window
                if(ans > right - left + 1){
                    ans = right - left + 1; // Update the size of the smallest window
                    sIndex = left;  // Update the starting index of the smallest window
                }
                // Restore the frequency of the character at the left pointer
                hash[s[left]]++;
                // If the character was part of t and is no longer satisfied, decrement count
                if(hash[s[left]] > 0){
                    count--;
                }
                // Move the left pointer forward to shrink the window
                left++;
            }
            right++;
        }
        return sIndex == -1 ? "" : s.substr(sIndex, ans);
    }
};

