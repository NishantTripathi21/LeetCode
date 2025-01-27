class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        //vector<int>smaller(prices.size(),-1);
        for( int i = prices.size()-1; i>= 0; i--) {
            while( !st.empty() && st.top() > prices[i]) {
                st.pop();
            }
            int temp = prices[i];
            prices[i] = st.empty() ? prices[i] :prices[i]-st.top();
            st.push(temp);
        }
        return prices;
    }
};
