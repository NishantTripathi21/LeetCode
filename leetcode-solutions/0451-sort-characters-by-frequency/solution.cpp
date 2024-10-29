class Solution {
public:
class mycomp{
    public:
    bool operator()(pair<char,int>a,pair<char,int>b){
        return a.second > b.second;
    }
};
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }
        vector<pair<char, int>> freqVec(freqMap.begin(), freqMap.end());
        sort(freqVec.begin(), freqVec.end(),mycomp());
        string result;
        for(auto& pair: freqVec){
            result += string(pair.second, pair.first); // add the character `pair.second` times
        }
        return result;
    }
};
