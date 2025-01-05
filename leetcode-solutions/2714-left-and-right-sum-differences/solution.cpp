class Solution {
public:
    vector<int> method1( vector<int>& nums){
        vector<int>leftSum;
        int ls = 0;
        leftSum.push_back(0);
        for( int i =1; i<nums.size(); i++){
            ls += nums[i-1];
            leftSum.push_back(ls);
        }
        int rightSum = 0;
        for( int i = nums.size() - 2; i >=0; i--){
            rightSum += nums[i+1];
            leftSum[i] = abs(leftSum[i] - rightSum);
        }
        return leftSum;
    }
    vector<int> leftRightDifference(vector<int>& nums) {
        return method1(nums);
    }
};
