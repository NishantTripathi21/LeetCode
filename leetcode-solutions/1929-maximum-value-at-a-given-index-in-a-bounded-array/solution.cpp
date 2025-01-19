class Solution {
public:
    long long calculateSum(int x, int n, int index) {
        long long leftCount = index;        // Elements to the left of `index`
        long long rightCount = n - index - 1; // Elements to the right of `index`

        // Sum of the left part
        long long leftSum = 0;
        if (x > leftCount) {
            leftSum = (long long)(x - leftCount + x - 1) * leftCount / 2;
        } 
        else{
            leftSum = (long long)x * (x - 1) / 2 + (leftCount - x + 1);
        }

        // Sum of the right part
        long long rightSum = 0;
        if (x > rightCount) {
            rightSum = (long long)(x - rightCount + x - 1) * rightCount / 2;
        } else {
            rightSum = (long long)x * (x - 1) / 2 + (rightCount - x + 1);
        }

        return leftSum + rightSum + x; // Total sum including nums[index]
    }

    // Function to find the maximum value of nums[index]
    int method(int n, int index, int maxSum) {
        int left = 1, right = maxSum, result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (calculateSum(mid, n, index) <= maxSum) {
                result = mid; // Update the result
                left = mid + 1; // Try for a larger value
            } else {
                right = mid - 1; // Try for a smaller value
            }
        }

        return result;
    }
    int maxValue(int n, int index, int maxSum) {
        return method(n,index,maxSum);
    }
};
