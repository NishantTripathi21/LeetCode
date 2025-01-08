class Solution {
public:
    bool implement( string s, string t){
        int i = 0; //  string s
        int j = 0; // string t
        int n = s.size();
        int range = -1; // Stores the last valid position for 'L' character in target
        
        // Loop through both strings until the end
        while (i < n) {
            // Skip all underscores in s
            while (i < n && s[i] == '_') {
                i++;
            }
            // Skip all underscores in t
            while (j < n && t[j] == '_') {
                j++;
            }
            
            // If both pointers reach the end of their respective strings simultaneously, return true
            if (i == n && j == n) return true;

            // If the characters at current positions are different, transformation is not possible
            if (s[i] != t[j]) return false;

            // 'L' in target should occur at the same index or earlier index in start
            if (s[i] == 'L' && (j <= range || j > i)) {
                return false;
            }

            // 'R' in target should occur at the same index or later index in start
            else if (s[i] == 'R' && i > j) {
                return false;
            }

            // Update the last valid position for 'L' in target
            range = j;

            i++;
            j++;
        }
        // Skip any remaining underscores in both strings
        while (i < n && s[i] == '_') {
            i++;
        }
        while (j < n && t[j] == '_') {
            j++;
        }
        // Return true if both pointers reach the end of their respective strings
        return i == n && j == n;
    }
    bool canChange(string start, string target) {
        // Ensure that the number of 'L', 'R', and spaces are the same in both strings
        // The relative ordering of 'L' and 'R' must be maintained
        // 'L' in target must not move to the right of its position in start
        // 'R' in target must not move to the left of its position in start
        return implement(start,target);

    }
};
