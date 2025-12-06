class Solution {
public:
    bool helper2(int x) {
        int left = 31;
        while (left > 0 && ((x >> left) & 1) == 0)left--;
        int right = 0;

        while (left > right) {
            int lbit = (x >> left) & 1;
            int rbit = (x >> right) & 1;
            if (lbit != rbit) return false;
            left--;
            right++;
        }
        return true;
    }
    int helper(int x) {
        if (helper2(x)) return 0;
        for (int i = 1; ; i++) {
            if (x - i >= 0 && helper2(x - i))return i;
            if (helper2(x + i)) return i;
        }
    }
    vector<int> minOperations(vector<int>& nums) {
        vector<int> ans;
        for (int x : nums){
            ans.push_back(helper(x));
        }
        return ans;
    }
};
