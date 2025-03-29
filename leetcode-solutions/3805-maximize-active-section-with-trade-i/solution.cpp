class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int length = s.size();
        int initialOnes = 0;
        for (char ch : s) {
            if (ch == '1') ++initialOnes;
        }
        string modifiedStr = "1" + s + "1";
        int modLength = modifiedStr.size();
        vector<pair<char, int>> mdf;
        char currentChar = modifiedStr[0];
        int freq = 1;
        for (int i = 1; i < modLength; i++) {
            if (modifiedStr[i] == currentChar) {
                freq++;
            }
            else {
                mdf.push_back({currentChar, freq});
                currentChar = modifiedStr[i];
                freq = 1;
            }
        }
        mdf.push_back({currentChar, freq});
        int maxIncrease = 0;
        for (int i = 1; i < mdf.size() - 1; i++) {
            if (mdf[i].first == '1') {
                if (mdf[i - 1].first == '0' && mdf[i + 1].first == '0') {
                    int gain = mdf[i - 1].second + mdf[i + 1].second;
                    maxIncrease = max(maxIncrease, gain);
                }
            }
        }
        int finalResult = initialOnes + maxIncrease;
        return min(finalResult, length);
    }
};
