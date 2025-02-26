class Solution {
public:
    int usingHint( vector<int>& nums) {
        int sum = 0;
        int maxSum1 = INT_MIN;
        int sum2 = 0;
        int maxSum2 = INT_MAX;
        for(int i = 0; i< nums.size(); i++) {
            sum += nums[i];
            sum2 += nums[i];
            maxSum1 = max(maxSum1,sum);
            maxSum2 = min(maxSum2,sum2);
            if( sum < 0)sum = 0;
            if( sum2 > 0)sum2 = 0;
        }

        return max(abs(maxSum1),abs(maxSum2));
    }
    int maxAbsoluteSum(vector<int>& nums) {
        // priority_queue<int>maxHeap; // to store positive max sum
        // priority_queue<int,vector<int>,greater<int>>minHeap; // negative sum

        // int sum = 0;
        // int maxSum = 0;
        // maxHeap.push(0);
        // minHeap.push(0);
        // for(int i= 0; i< nums.size(); i++) {
        //     int ele = nums[i];
        //     sum += ele;
        //     int temp = 0;
        //     if(!maxHeap.empty()) {
        //         temp = abs(maxHeap.top() - sum);
        //     }
        //     if(!minHeap.empty()) {
        //         temp = max(temp, abs(minHeap.top()- sum));
        //     }
        //     maxSum = max(maxSum,temp);
        //     if(sum >= 0)maxHeap.push(sum);
        //     else minHeap.push(sum);
        // }
        // return maxSum;
        return usingHint(nums);
    }
};
