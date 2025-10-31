class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int index = 1;
        int i = 0;
        vector<int>arr(2);
        while(index < nums.size()) {
            if(nums[index] == nums[index-1]) {
                arr[i] = nums[index];
                i++;
            }
            index++;
        }
        return arr;
    }
};
