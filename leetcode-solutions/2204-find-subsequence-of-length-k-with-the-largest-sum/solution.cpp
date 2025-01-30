class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (int i = 0; i < nums.size(); i++) {
            minHeap.emplace(nums[i], i);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<pair<int, int>> selected;
        while (!minHeap.empty()) {
            selected.push_back(minHeap.top());
            minHeap.pop();
        }

        sort(selected.begin(), selected.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        });

        vector<int> result;
        for (auto& p : selected) {
            result.push_back(p.first);
        }
        return result;
    }
};
