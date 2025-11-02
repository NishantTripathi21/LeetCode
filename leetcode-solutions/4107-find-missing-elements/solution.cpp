class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l = nums[0];
        int h = nums.back();
        unordered_set<int>st(nums.begin(),nums.end());
        vector<int>ans;
        for(int i= l; i<= h;  i++) {
            if(!st.count(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
