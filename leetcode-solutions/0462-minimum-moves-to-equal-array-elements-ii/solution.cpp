class Solution {
public:
    int method1( vector<int>& nums) {
        sort( nums.begin(), nums.end());
        long long rightSum = 0;
        for ( int i: nums){
            rightSum += i;
        }
        int minOp = INT_MAX;
        int size = nums.size();
        long long leftSum = 0;
        for (int i = 0; i < size; i++) {
            long long operations = (rightSum - (long long)(size - i) * nums[i]) + (long long)i * nums[i] - leftSum;
            if( operations < minOp){
                minOp = operations;
            }
            //minOp = min(operations, minOp);
            leftSum += nums[i];
            rightSum -= nums[i];
        }
        return minOp;
    }

    int minMoves2(vector<int>& nums) {
        return method1(nums);
    }
};
