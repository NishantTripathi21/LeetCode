class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();
        set<int>st;
        int minDiff = INT_MAX;
        for( int i = x; i< nums.size(); i++){
            int ele = nums[i];
            int ele2= nums[i-x];
            st.insert(ele2);
            auto lb = st.lower_bound(ele); 
            if (lb != st.end()){
                minDiff = min(minDiff, abs(*lb - ele));
            }
            if (lb != st.begin()) {
                --lb;
                minDiff = min(minDiff, abs(*lb - ele));
            }
        }
    return minDiff;
    }
};
