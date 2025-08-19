class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> actualProfitRange(n, 0); 
        int right = 0;
        int left = 0;
        long long rangePro = 0;          // running profit in current window
        long long profitWithoutChange = 0;  // total profit without modifications

        while (right < n) {
            profitWithoutChange += 1LL * prices[right] * strategy[right];
            rangePro += 1LL * prices[right] * strategy[right];

            if (right - left + 1 >= k) {
                actualProfitRange[right] = rangePro;
                rangePro -= 1LL * prices[left] * strategy[left];
                left++;
            }
            right++;
        }

        right = k / 2;
        left = k / 2;
        long long change = 0;
        long long maxProfit = profitWithoutChange;

        while (right < n) {
            change += prices[right];  
            if (right - left + 1 >= k / 2) {
                long long pro = profitWithoutChange - actualProfitRange[right] + change;
                maxProfit = max(maxProfit, pro);
                change -= prices[left];
                left++;
            }
            right++;
        }
        return maxProfit;
    }
};
