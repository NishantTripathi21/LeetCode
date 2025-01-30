class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, long long> totalViews; 
        unordered_map<string, pair<int, string>> bestVideo; // {creator -> {maxViews, lexicographically smallest id}}
        int n = creators.size();
        long long maxPopularity = 0;

        for (int i = 0; i < n; i++) {
            string& creator = creators[i];
            string& id = ids[i];
            int view = views[i];

            totalViews[creator] += view;
            maxPopularity = max(maxPopularity, totalViews[creator]);

            if (bestVideo.find(creator) == bestVideo.end() || view > bestVideo[creator].first || 
                (view == bestVideo[creator].first && id < bestVideo[creator].second)) {
                bestVideo[creator] = {view, id};
            }
        }

        vector<vector<string>> result;
        for (auto& [creator, totalView] : totalViews) {
            if (totalView == maxPopularity) {
                result.push_back({creator, bestVideo[creator].second});
            }
        }
        return result;
    }
};
