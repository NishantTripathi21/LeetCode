class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>minHeap;
        // insert first k elements in minHeap
        for( int i= 0; i< k; i++) {
            minHeap.push(nums[i]);
        }
        int index = k;
        while( index < nums.size()) {
            if( minHeap.top() > nums[index]){
                index++;
                continue;
            }
            minHeap.pop();
            minHeap.push(nums[index]);
            index++;
        }
        return minHeap.top();
    }
};
