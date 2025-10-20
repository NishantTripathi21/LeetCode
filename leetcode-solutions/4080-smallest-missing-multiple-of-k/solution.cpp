class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int ans = k;
        unordered_set<int>st(nums.begin(),nums.end());
        while(true) {
            if(st.find(ans) == st.end()) {
                return ans;
            }
            ans += k;
        }
        return ans;
    }
};
