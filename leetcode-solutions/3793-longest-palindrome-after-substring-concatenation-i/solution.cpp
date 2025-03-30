class Solution {
public:
    vector<string> generateSubstrings(string &str) {
        vector<string> substrings = {""};
        int length = str.size();
        for (int start = 0; start < length; start++) {
            for (int end = start; end < length; end++) {
                substrings.push_back(str.substr(start, end - start + 1));
            }
        }
        return substrings;
    }
    bool isPalind(string & s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left++] != s[right--]) 
                return false;
        }
        return true;
    }
    int longestPalindrome(string s, string t) {
        vector<string> substringsS = generateSubstrings(s);
        vector<string> substringsT = generateSubstrings(t);
        int maxi = 0;
        for ( string &subS : substringsS) {
            for ( string &subT : substringsT) {
                string combined = subS + subT;
                if (isPalind(combined)) {
                    maxi = max(maxi, (int)combined.size());
                }
            }
        }

        return maxi;
    }
};
