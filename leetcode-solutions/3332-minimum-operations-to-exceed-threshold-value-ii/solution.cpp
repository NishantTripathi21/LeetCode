class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>>minHeap;
        for( long long i: nums){
            minHeap.push(i);
        }
        int operations = 0;
        while( minHeap.size() >= 2) {
            long long top1= minHeap.top();
            minHeap.pop();
            if( top1 >= k)return operations;
            long long top2 = minHeap.top();
            minHeap.pop();
            long long newElement = (long long)min(top1,top2)*2 + max(top1,top2);
            minHeap.push(newElement);
            operations++;
        }
        return operations;
    }
};
