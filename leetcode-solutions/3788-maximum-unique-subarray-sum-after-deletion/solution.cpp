class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int>st;
        int sum = 0;
        int maxEle = *max_element(nums.begin(),nums.end());
        if(maxEle < 0) {
            return maxEle;
        }
        for(int i: nums) {
            if(i > 0 && st.find(i) == st.end()){
                sum += i;
                st.insert(i);
            }
        }
        return sum;
    }
};
