class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap; // To store the number and its index

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i]; // Find the complement of the current number

            if (numMap.find(complement) != numMap.end()) {
                // If complement exists in the map, we found the solution
                return { numMap[complement], i };
            }
            // Store the current number and its index in the map
            numMap[nums[i]] = i;
        }
        return {};
        
    }
};
