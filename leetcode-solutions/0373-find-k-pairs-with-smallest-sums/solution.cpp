class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k == 0) return result;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        for (int j = 0; j < nums2.size() && j < k; ++j) {
            minHeap.push({nums1[0] + nums2[j], 0, j});
        }

        while (k-- > 0 && !minHeap.empty()) {
            auto [sum, i, j] = minHeap.top();
            minHeap.pop();
            result.push_back({nums1[i], nums2[j]});
            if (i + 1 < nums1.size()) {
                minHeap.push({nums1[i + 1] + nums2[j], i + 1, j});
            }
        }
        return result;
    }
};
