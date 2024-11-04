class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans(nums.size(),-1);
        stack<int>st;
        st.push(-1);
        int i=nums.size() -1;
        while(i>=0){
            int element=nums[i];
            while(st.size() > 1 && st.top() <= element){
                st.pop();
            }
            st.push(element);
            i--;
        }
        cout<<st.top()<<endl;
        i=nums.size()-1;
        while(i>=0){
            int element=nums[i];
            while(st.size() > 1 && st.top() <= element){
                st.pop();
            }
            ans[i]=st.top();
            st.push(element);
            i--;
        }
        return ans;
    }
};
