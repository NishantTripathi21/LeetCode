class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        for (int i = 1; i < items.size(); i++) {
            items[i][1] = max(items[i][1], items[i-1][1]);
        }

        vector<int> ans(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            int maxPrice = queries[i];
            int low = 0, high = items.size() - 1, maxBeauty = 0;

            while (low <= high) {
                int mid = (low + high) / 2;
                if (items[mid][0] <= maxPrice) {
                    maxBeauty = items[mid][1]; 
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            ans[i] = maxBeauty;
        }

        return ans;
    }
};
