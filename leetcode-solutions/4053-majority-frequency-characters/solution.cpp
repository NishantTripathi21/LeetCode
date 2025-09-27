class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char,int> freq;
        for(char c : s) freq[c]++;
        
        unordered_map<int, vector<char>> groups;
        for(auto &p : freq){
            groups[p.second].push_back(p.first);
        }
        int bestSize = 0, bestFreq = 0;
        vector<char> bestGroup;
        
        for(auto &g : groups){
            int k = g.first;
            int size = g.second.size();
            
            if(size > bestSize || (size == bestSize && k > bestFreq)){
                bestSize = size;
                bestFreq = k;
                bestGroup = g.second;
            }
        }
        
        string ans(bestGroup.begin(), bestGroup.end());
        return ans;
    }
};
