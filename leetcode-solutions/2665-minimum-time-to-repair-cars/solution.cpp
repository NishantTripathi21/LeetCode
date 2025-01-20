class Solution {
public:
    bool canRepairAll(const vector<int>& ranks, int cars, long long maxTime) {
        long long totalCars = 0;
        for (int rank : ranks) {
            long long maxCars = (sqrt(maxTime / rank));
            totalCars += maxCars;
            if (totalCars >= cars) return true;
        }
        return totalCars >= cars;
    }
    long long method1(vector<int>& ranks, int cars){
        long long left = 0;
        long long right = (long long)(ranks[0]) * cars * cars;
        long long result = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canRepairAll(ranks, cars, mid)) {
                result = mid;
                right = mid - 1; 
            }
            else {
                left = mid + 1;
            }
        }
        return result;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        return method1(ranks,cars);
    }
};
