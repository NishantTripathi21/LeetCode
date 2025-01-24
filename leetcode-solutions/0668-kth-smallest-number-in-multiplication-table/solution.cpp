class Solution {
public:
    int countLessEqual(int mid, int m, int n) {
        int count = 0;
        for (int i = 1; i <= m; i++) {
            count += min(mid / i, n);  // Count elements in row i <= mid
        }
        return count;
    }

    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (countLessEqual(mid, m, n) < k) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
};
