class Solution {
public:
    int method( vector<int>& inventory, int orders) {
        const int MOD = 1e9 + 7;
        sort(inventory.rbegin(), inventory.rend()); // Sort in descending order
        inventory.push_back(0); // Add a dummy zero for easier handling
        long long result = 0;
        int width = 1; // Number of colors at the current level

        for (int i = 0; i < inventory.size() - 1 && orders > 0; i++, width++) {
            int current = inventory[i];
            int next = inventory[i + 1];
            long long count = (long long)(current - next) * width; // Total balls we can sell at this level

            if (orders >= count) {
                // Sell all balls down to the next level
                result += (long long)(current + next + 1) * (current - next) / 2 * width;
                orders -= count;
            }
            else {
                // Sell only the required number of balls
                int fullRows = orders / width;
                int remainder = orders % width;
                result += (long long)(current + current - fullRows + 1) * fullRows / 2 * width;
                result += (long long)remainder * (current - fullRows);
                orders = 0;
            }

            result %= MOD;
        }

        return result;
    }
    int maxProfit(vector<int>& inventory, int orders) {
        return method( inventory,orders);

    }
};
