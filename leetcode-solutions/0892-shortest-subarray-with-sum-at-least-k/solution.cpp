class Solution {
public:
    int shortestSubarray(vector<int>& nums, int K) {
        int n = nums.size();
        
        deque<int> deq;
        vector<long long> cumulativeSum(n, 0);

        int result = INT_MAX;
        int right = 0;

        while (right < n) {
            if (right == 0){
                cumulativeSum[right] = nums[right];
            }   
            else{
                cumulativeSum[right] = cumulativeSum[right - 1] + nums[right];
            }
            if (cumulativeSum[right] >= K){
                result = min(result, right + 1);
            }
            while (!deq.empty() && cumulativeSum[right] - cumulativeSum[deq.front()] >= K) {
                result = min(result, right - deq.front());  
                deq.pop_front();  
            }

            // Maintain the monotonic property of the deque (increasing order of cumulative sums)
            while (!deq.empty() && cumulativeSum[right] <= cumulativeSum[deq.back()]) {
                deq.pop_back();
            }

            deq.push_back(right);

            right++; 
        }
        return result == INT_MAX ? -1 : result;
    }
};
