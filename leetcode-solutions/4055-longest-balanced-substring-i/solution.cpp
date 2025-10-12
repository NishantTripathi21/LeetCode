class Solution {
public:
    bool isBalanced(unordered_map<char,int>& freq) {
        int count = 0;
        for (auto [ch, f] : freq) {
            if (count == 0) count = f;      
            else if (f != count) return false;
        }
        return true;
    }
    int longestBalanced(string s) {
        int n = s.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;
            for (int j = i; j < n; j++) {
                freq[s[j]]++;
                if(isBalanced(freq)) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};
