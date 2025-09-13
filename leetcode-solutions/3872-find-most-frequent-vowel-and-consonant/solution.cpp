class Solution {
public:
    int maxFreqSum(string s) {
        int feqV = 0;
        int feqC = 0;
        unordered_map<char,int>mp;
        for(char ch: s) {
            mp[ch]++;
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                if(mp[ch] >= feqV) {
                    feqV = mp[ch];
                }
            }
            else {
                if(mp[ch] >= feqC) {
                    feqC = mp[ch];
                }
            }
        }
        return feqC + feqV;
    }
};
