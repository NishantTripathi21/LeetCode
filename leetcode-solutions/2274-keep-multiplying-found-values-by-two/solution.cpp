class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>st(nums.begin(),nums.end());
        while(true) {
            if(st.count(original)) {
                original = original*2;
            }
            else return original;
        }
        return -1;
    }
};
