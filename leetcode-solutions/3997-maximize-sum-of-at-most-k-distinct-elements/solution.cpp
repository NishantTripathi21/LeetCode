class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int>st(nums.begin(),nums.end());
        vector<int>ans;
        for (auto it = st.rbegin(); it != st.rend(); ++it) {
            ans.push_back(*it);
            k--;
            if(k == 0)break;
        }
        return ans;
    }
};
