class Solution {
public:
    struct compare{
        bool operator() (pair<char,int>&a, pair<char,int>&b) {
            if(a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        }
    };
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, compare> minHeap;
        unordered_set<int>removed; // stores removed indices
        for( int i = 0; i< s.size(); i++) {
            if( s[i] != '*') {
                minHeap.push({s[i],i});
                continue;
            }
            auto top = minHeap.top();
            minHeap.pop();
            removed.insert(top.second);
            removed.insert(i);
        }
        string result;
        for( int i= 0; i< s.size(); i++) {
            if( removed.find(i) == removed.end()) {
                result += s[i];
            }
        }
        return result;
    }
};
