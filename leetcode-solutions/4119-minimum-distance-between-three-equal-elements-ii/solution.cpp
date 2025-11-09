class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> index;

        for (int i = 0; i < n; i++) {
            index[nums[i]].push_back(i);
        }

        int mini = INT_MAX;

        for (auto it : index) {
            auto v = it.second;
            if (v.size() < 3) continue;
            for (int i = 0; i + 2 < v.size(); i++) {
                int dist = abs(v[i] - v[i+1]) + abs(v[i+1] - v[i+2]) + abs(v[i+2] - v[i]);
                mini = min(mini, dist);
            }
        }

        return (mini == INT_MAX) ? -1 : mini;
    }
};
