class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int mod = 1e9+7;
        vector<long long>preSum( nums.size()+1);
        preSum[0] = 0;
        for( int i = 1; i<= nums.size(); i++){
            preSum[i] = nums[i-1] + preSum[i-1];
        }
        
        vector<int>prevSmaller(nums.size(),-1);
        vector<int>nextSmaller(nums.size(),nums.size());

        // calculate next smaller
        stack<int>st;
        for( int i= nums.size()-1; i>=0; i--) {
            while( !st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                nextSmaller[i] = st.top();
            }
            st.push(i);
        }

        // calculate prevSmaller
        stack<int>st2;
        for( int i = 0; i< nums.size(); i++) {
            while(!st2.empty() && nums[st2.top()] >= nums[i]){
                st2.pop();
            }
            if(!st2.empty()){
                prevSmaller[i] = st2.top();
            }
            st2.push(i);
        }

        // calculate maximum-minProduct as asked in question
        long long maxiProduct = INT_MIN;
        for(int i= 0; i< nums.size(); i++) {
            long long upperRange = nextSmaller[i];
            long long lowerRange = prevSmaller[i];
            long long minProduct = (long long)( preSum[upperRange] - preSum[lowerRange+1]) * nums[i];
            maxiProduct = max( maxiProduct, minProduct);
        }
        return maxiProduct % mod;
    }
};
