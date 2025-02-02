class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
    
        for (char ch : s) {
            freq[ch - 'a']++;
        }
    
        int max_odd = INT_MIN, min_even = INT_MAX;
    
        for (int f : freq) {
            if (f > 0) {
                if (f&1) { 
                    max_odd = max(max_odd, f);
                }
                else{
                    min_even = min(min_even, f);
                }
            }
        }    
        return max_odd - min_even;
    }
};
