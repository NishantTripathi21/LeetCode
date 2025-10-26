class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int>maxHeap;
        for(int i= 0;  i<n;  i++){
            maxHeap.push(abs(nums[i]));
        }

        int half = ceil((double)n/(double)2);
        long  long ans = 0;
        while(half--){
            long long val = maxHeap.top();
            maxHeap.pop();
            ans += (long long )val*val;
        }

        while(!maxHeap.empty()) {
            long long val =  maxHeap.top();
            maxHeap.pop();
            ans -= (long long )val*val;
        }
        return ans;



    }
};
