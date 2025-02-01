class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first) {
                return a.second < b.second; // Lexicographically bigger string should be on top
            }
            return a.first > b.first; // Min-heap based on integer value
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for( string str: words) {
            mp[str]++;
        }

        priority_queue<pair<int,string>, vector<pair<int,string>>, Compare> minHeap;
        for( auto it: mp) {
            minHeap.push({it.second,it.first});
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        vector<string>ans(k);
        while(!minHeap.empty()){
            auto top = minHeap.top();
            minHeap.pop();
            ans[k-1]= top.second;
            k--;
        }
        return ans;

    }
};
