class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int ans = 0;
        int i = 0;

        while (i < n) {
            int j = i;
            int total = 0;
            int maxi = 0;
            while (j < n && colors[j] == colors[i]) {
                total += neededTime[j];
                maxi = max(maxi, neededTime[j]);
                j++;
            }

            ans += total - maxi;
            i = j;
        }

        return ans;
    }
};
