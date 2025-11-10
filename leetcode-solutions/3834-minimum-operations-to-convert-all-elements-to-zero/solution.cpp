class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int>ns(n,-1);

        stack<int>st;
        st.push(-1);

        for(int i= n-1; i>= 0; i--) {
            while(st.top() != -1 && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            ns[i] = st.top();
            st.push(i);
        }

        unordered_map<int,int>mp;
        int count = 0;
        for(int i= 0; i< n; i++) {
            if(nums[i] == 0)continue;
            int index = ns[i];
            if(index == -1 && mp[nums[i]] != n) {
                count++;
                mp[nums[i]] = n;
                continue;
            }

            if( i >= mp[nums[i]]) {
                count++;
                if(index == -1) {
                    mp[nums[i]] = n;
                }
                else mp[nums[i]] = index;
            }
        }
        return count;
    }
};
