class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<vector<double> , vector<vector<double>>, greater<vector<double>>>minHeap;
        //push N-1 elements in minHeap
        int n = arr.size();
        for( int i= 0; i< arr.size(); i++) {
            minHeap.push({ (double)arr[i]/arr[n-1], (double)i, (double)n-1 });
        }

        int popped = 1;
        
        while( popped < k) {
            auto top = minHeap.top();
            minHeap.pop();
            popped++;
            int nextNumIndex = top[1];
            int nextDenoIndex = top[2]-1;
            
            if(nextNumIndex == nextDenoIndex){
                continue;
            }
            double nextProspect = (double)arr[nextNumIndex]/arr[nextDenoIndex];
            minHeap.push({nextProspect,(double)nextNumIndex,(double)nextDenoIndex});

        }
        int one = minHeap.top()[1];
        int two = minHeap.top()[2];
        return {arr[one],arr[two]};
    }
};
