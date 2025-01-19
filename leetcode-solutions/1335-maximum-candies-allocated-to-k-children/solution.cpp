class Solution {
public:
    bool canDistribute(const vector<int>& candies, long long k, int mid) {
        long long count = 0;
        for (int candy : candies) {
            count += candy / mid; 
            if (count >= k) return true;
        }
        return count >= k;
    }
    int method(vector<int>& candies, long long k) {
        int left = 1, right = *max_element(candies.begin(), candies.end());
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDistribute(candies, k, mid)) {
                result = mid; 
                left = mid + 1; 
            } 
            else{
                right = mid - 1;
            }
        }

        return result;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        return method(candies,k);
    }
};
