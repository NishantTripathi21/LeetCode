class Solution {
public:
    bool canRunKRobots( vector<int>& chargeTimes, vector<int>& runningCosts, long long budget, int k) {
        int n = chargeTimes.size();
        long long runningCostSum = 0;
        multiset<int> window;
        int left = 0;
        for (int right = 0; right < k; ++right) {
            runningCostSum += runningCosts[right];
            window.insert(chargeTimes[right]);
        }

        if (*window.rbegin() + k * runningCostSum <= budget) {  // *window.rbegin() gives the maximum element
            return true;
        }

        for (int right = k; right < n; ++right) {
            runningCostSum += runningCosts[right];
            window.insert(chargeTimes[right]);
            runningCostSum -= runningCosts[left];
            window.erase(window.find(chargeTimes[left]));
            left++;
            
            if (*window.rbegin() + k * runningCostSum <= budget) {  // *window.rbegin() gives the maximum element
                return true;
            }
        }

        return false;

    }

    int method(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();

        int left = 1, right = n, result = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canRunKRobots(chargeTimes, runningCosts, budget, mid)) {
                result = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return result;
    }
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        return method( chargeTimes, runningCosts,budget);
    }
};
