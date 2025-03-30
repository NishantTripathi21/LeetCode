class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int n = cost.size();
        vector<int> answer(n);
        int minCost = cost[0];
        answer[0] = minCost;
        for (int i = 1; i < n; ++i) {
            minCost = min(minCost, cost[i]);
            answer[i] = minCost;
        }
        return answer;
    }
};
