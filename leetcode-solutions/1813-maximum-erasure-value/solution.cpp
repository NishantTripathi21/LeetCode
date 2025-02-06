class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = 0, currentSum = 0, maxScore = 0;
        unordered_set<int> uniqueElements;

        for (int right = 0; right < nums.size(); ++right) {
            while (uniqueElements.find(nums[right]) != uniqueElements.end()) {
                uniqueElements.erase(nums[left]);
                currentSum -= nums[left];
                left++;
            }
            uniqueElements.insert(nums[right]);
            currentSum += nums[right];
            maxScore = max(maxScore, currentSum);
        }
        return maxScore;
    }
};
