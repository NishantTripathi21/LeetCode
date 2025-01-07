class Solution {
public:
    long long method1(std::vector<int>& beans) {
        // Sort the vector to organize the beans in ascending order
        sort(beans.begin(), beans.end());
        int n = beans.size(); // Get the number of beans
        long long leftSum = 0; // Sum of beans on the left of current index
        long long rightSum = 0; // Sum of beans on the right of current index
        long long minRemoval = LLONG_MAX; // Initialize minRemoval with maximum possible value

        // Calculate the initial rightSum which is the sum of all beans
        for (long long i : beans) {
            rightSum += i;
        }

        // Iterate through each bean
        for (int i = 0; i < n; i++) {
            // Calculate the potential minimum removal at the current index
            long long currentRemoval = leftSum + (rightSum - (long long)(n - i) * beans[i]);
            // Update minRemoval if the currentRemoval is smaller
            if (minRemoval > currentRemoval) {
                minRemoval = currentRemoval;
            }
            // Update leftSum and rightSum for the next iteration
            leftSum += beans[i];
            rightSum -= beans[i];
        }

        // Return the minimum number of beans to remove
        return minRemoval;
    }
    long long minimumRemoval(vector<int>& beans) {
        return method1(beans);
    }
};
