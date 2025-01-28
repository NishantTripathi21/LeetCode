class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });

        int maxDefense = 0;
        int weakCount = 0;

        for (auto& property : properties) {
            if (property[1] < maxDefense) {
                weakCount++;
            }
            else {
                maxDefense = property[1];
            }
        }

        return weakCount;
    }
};
