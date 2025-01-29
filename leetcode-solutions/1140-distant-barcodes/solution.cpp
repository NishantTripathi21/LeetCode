class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int>ans;
        if( barcodes.size() == 1)return barcodes;
        unordered_map<int,int>frequency;
        for( int i: barcodes) {
            frequency[i]++;
        }
        priority_queue<pair<int,int>>maxHeap;
        for(auto i: frequency) {
            int element = i.first;
            int occurance = i.second;
            maxHeap.push({occurance,element});
        }
        while(!maxHeap.empty()) {
            auto top1 = maxHeap.top();
            maxHeap.pop();
            auto top2=  maxHeap.top();
            maxHeap.pop();
            ans.push_back(top1.second);
            ans.push_back(top2.second);
            top1.first--;
            top2.first--;
            if( top1.first > 0){
                maxHeap.push(top1);
            }
            if( top2.first > 0){
                maxHeap.push(top2);
            }

            if( maxHeap.size() == 1){
                ans.push_back(maxHeap.top().second);
                maxHeap.pop();
            }
        }
        return ans;
    }
};
