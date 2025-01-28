class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<long long>prefix(n);
        vector<long long>suffix(n);
        stack<int>st;
        for( int i = 0; i< n; i++) {
            while( !st.empty() && maxHeights[st.top()] > maxHeights[i]){
                st.pop();
            }
            if( st.empty()) {
                prefix[i] = (long long)(i+1)*maxHeights[i];
            }
            else{
                prefix[i] = (long long)maxHeights[i]*(i-st.top()) + prefix[st.top()];
            }
            st.push(i);
        }
        // suffix
        stack<int>st2;
        for( int i = n-1; i>= 0; i--) {
            while( !st2.empty() && maxHeights[st2.top()] > maxHeights[i]){
                st2.pop();
            }
            if( st2.empty()) {
                suffix[i] = (long long) (n-i)*maxHeights[i];
            }
            else{
                suffix[i] = (long long) maxHeights[i]*(st2.top()-i) + suffix[st2.top()];
            }
            st2.push(i);
        }
        long long maxSum = 0;
        for( int i= 0; i< n; i++) {
            maxSum = max( maxSum, (long long)prefix[i]+suffix[i] - (maxHeights[i]));
        }
        return maxSum;
    }
};
