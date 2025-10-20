class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int size = 0;
        int n = nums.size();
        for(int i= 0; i< n; i++) {
            unordered_set<int>odds,evens;
            for(int j= i; j< n; j++) {
                if(nums[j] & 1) {
                    odds.insert(nums[j]);
                }
                else evens.insert(nums[j]);

                if(odds.size() == evens.size()) {
                    size = max(size, j-i+1);
                }
            }
        }
        return size;
    }
};
