class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        multiset<int> track; 
        int left = 0;
        int right = 0;
        int ans = INT_MIN;
        while(right < points.size()) {
            int xj = points[right][0];
            int yj = points[right][1];
            while (left < right && xj - points[left][0] > k) {
                int xi = points[left][0];
                int yi = points[left][1];
                track.erase(track.find(yi - xi));
                ++left;
            }
            if (!track.empty()) {
                ans = max(ans, *track.rbegin() + yj + xj);
            }
            track.insert(yj - xj);
            right++;
        }
        return ans;
    }
};
