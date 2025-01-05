class Solution {
public:
    vector<int> method1( vector<int>& nums){
        vector<int>prefixProduct(nums.size(),1); // used to store prefix product and later to store answer
        int prefix = 1;
        for( int i = 0; i< nums.size(); i++){
            prefixProduct[i] = prefix;
            prefix *= nums[i];
        }
        int suffix = 1;
        for( int i = nums.size()-1; i>=0; i--){
            int product = prefixProduct[i] * suffix;
            suffix *= nums[i];
            prefixProduct[i] = product; // storing answer , now no use  ith index 
        }
        return prefixProduct;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        return method1(nums); // without using divide operator and in 0(N) tc
    }
};
