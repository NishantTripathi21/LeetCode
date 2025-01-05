class Solution {
public:
    vector<int> method1( vector<int>& nums){
        int leftSum = 0;
        vector<int> ans( nums.size(),0);
        int size = nums.size();
        for( int i: nums){
            leftSum += i;
        }
        int rightSum = 0;
        for( int i= nums.size()-1; i>= 0; i--){
            rightSum += nums[i];
            int absSum = ((i+1)*nums[i] - leftSum ) + (rightSum - (size - i)*nums[i] );
            ans[i] = absSum;
            leftSum -= nums[i];
        }
        return ans;

    }
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        return method1(nums);
    }
};
