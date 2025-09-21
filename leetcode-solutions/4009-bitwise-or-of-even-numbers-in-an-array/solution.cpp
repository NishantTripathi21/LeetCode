class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int r = 0;
        for (int num : nums) {
            if (num % 2 == 0) {
                r |= num;
            }
        }
        return r;
    }
};
