class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<bool>marked(n,false);
        for( int i= 0; i< n; i++) {
            minHeap.push({nums[i],i});
        }
        long long score = 0;
        while( !minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            int index = top.second;
            int element = top.first;
            if( marked[index] == true){
                continue;
            }
            marked[index] = true;
            if( index > 0 ){
                marked[index-1] = true;
            }
            if( index < n-1) {
                marked[index+1] = true;
            }
            score += element;
            //cout<<" index: "<<index<<" element: "<<element<<" score: "<<score<<endl;
        }
        return score;

    }
};
