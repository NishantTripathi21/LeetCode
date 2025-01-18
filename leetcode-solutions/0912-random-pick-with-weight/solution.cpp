class Solution {
private:
    vector<int> sum;
    int max;

public:
    Solution(vector<int>& w) {
        sum.resize(w.size());
        sum[0] = w[0];
        for (int i = 1; i < w.size(); ++i) {
            sum[i] = sum[i - 1] + w[i];
        }
        max = sum.back();
        srand(time(0)); // Seed the random number generator
    }

    int pickIndex() {
        int target = 1 + rand() % max;
        int low = 0, high = sum.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (sum[mid] == target) {
                return mid;
            }
            if (sum[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
