class Solution {
public:
    int method1( vector<int>& nums){
        int index = 0;
        int n = nums.size();
        int preMul = 1;
        int sufMul = 1;
        int maxi = INT_MIN;
        while ( index < nums.size()){
            preMul *= nums[index];
            sufMul *= nums[ n-index-1];
            maxi = max( maxi,max(preMul,sufMul));
            if( preMul == 0 ){
                preMul = 1;
            }
            if( sufMul == 0){
                sufMul = 1;
            }
            index++;
        }
        return maxi;
    }
    int maxProduct(vector<int>& nums) {
        return method1(nums);
    }
};
