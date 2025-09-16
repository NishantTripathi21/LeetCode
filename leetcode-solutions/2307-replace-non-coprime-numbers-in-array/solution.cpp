class Solution {
public:
    int lcm(int a, int b) {
        return (a / __gcd(a, b)) * b;  
    }
    void solve(stack<int>& st, int var) {
        int top = st.top();
        while(st.size() >= 1 && __gcd(var,top) > 1) {
            int lc = lcm(var,top);
            st.pop();
            var = lc;
            if(st.empty())break;
            top = st.top();
        } 
        st.push(var);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int>st;
        st.push(nums[0]);
        for(int i= 1; i< nums.size(); i++) {
            int var = nums[i];
            solve(st,var);
        }
        vector<int>ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
