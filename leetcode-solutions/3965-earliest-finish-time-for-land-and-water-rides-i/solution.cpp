class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minTime = INT_MAX;
        for (int i = 0; i < landStartTime.size(); ++i) {
            int landFinish = landStartTime[i] + landDuration[i];
            for (int j = 0; j < waterStartTime.size(); ++j) {
                int t = max(waterStartTime[j], landFinish) + waterDuration[j];
                minTime = min(minTime, t);
            }
        }

        for (int j = 0; j < waterStartTime.size(); ++j) {
            int waterFinish = waterStartTime[j] + waterDuration[j];
            for (int i = 0; i < landStartTime.size(); ++i) {
                int t = max(landStartTime[i], waterFinish) + landDuration[i];
                minTime = min(minTime, t);
            }
        }
        return minTime;
    }
};
