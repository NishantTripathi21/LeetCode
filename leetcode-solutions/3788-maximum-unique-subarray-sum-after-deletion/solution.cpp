class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum = 0;
        unordered_set<int>st;
        bool flag = true;
        int temp = INT_MIN;
        for(int i= 0; i< nums.size(); i++) {
            if(nums[i] >= 0) {
                flag = false;
            }
            temp = max(temp,nums[i]);
        }
        if(flag)return temp;
        for(int i: nums) {
            if(st.find(i) == st.end()  && i >= 1) {
                sum += i;
                st.insert(i);
            }
        }
        return sum;
    }
};
