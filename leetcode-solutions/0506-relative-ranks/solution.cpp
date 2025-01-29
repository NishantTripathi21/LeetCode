class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> indexedScores(n);
        for (int i = 0; i < n; i++) {
            indexedScores[i] = {score[i], i};
        }
        sort(indexedScores.rbegin(), indexedScores.rend());
        vector<string> result(n);

        for (int i = 0; i < n; i++) {
            int idx = indexedScores[i].second;
            if (i == 0) {
                result[idx] = "Gold Medal";
            }
            else if (i == 1) {
                result[idx] = "Silver Medal";
            }
            else if (i == 2) {
                result[idx] = "Bronze Medal";
            }
            else {
                result[idx] = to_string(i + 1);
            }
        }
        
        return result;
    }
};
