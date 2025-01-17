class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int left = 0, right = nums.size() - 1, leftIndex = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                leftIndex = mid;
                right = mid - 1; 
            } 
            else if(nums[mid] < target){
                left = mid + 1;
            } 
            else{
                right = mid - 1;
            }
        }

        if (leftIndex == -1) {
            return {};
        }

        left = 0, right = nums.size() - 1;
        int rightIndex = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                rightIndex = mid;
                left = mid + 1;
            } 
            else if(nums[mid] < target) {
                left = mid + 1;
            } 
            else{
                right = mid - 1;
            }
        }
        
        vector<int> result;
        for (int i = leftIndex; i <= rightIndex; ++i) {
            result.push_back(i);
        }

        return result;

    }
};
