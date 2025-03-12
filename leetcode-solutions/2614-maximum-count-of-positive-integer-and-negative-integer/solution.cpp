class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1, firstPos = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > 0) {
                firstPos = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        int pos = n - firstPos;

        left = 0, right = n - 1;
        int lastNeg = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < 0) {
                lastNeg = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        int neg = lastNeg + 1;

        return max(pos, neg);
    }
};
