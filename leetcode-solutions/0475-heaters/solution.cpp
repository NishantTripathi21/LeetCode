class Solution {
public:
    bool canCoverAllHouses(const vector<int>& houses, const vector<int>& heaters, int radius) {
        int i = 0; // Pointer for houses
        int j = 0; // Pointer for heaters

        while (i < houses.size()) {
            // Move the heater pointer until it's close enough to the current house
            while (j < heaters.size() && abs(heaters[j] - houses[i]) > radius) {
                j++;
            }
            if (j == heaters.size()) return false; 
            i++;
        }
        return true;
    }

    int method(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int left = 0, right = 1e9;
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canCoverAllHouses(houses, heaters, mid)) {
                result = mid; 
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        return method(houses,heaters);
    }
};
