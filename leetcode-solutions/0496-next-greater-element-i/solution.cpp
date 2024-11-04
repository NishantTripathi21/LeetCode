class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums2.size(),-1);
        stack<int>st;
        st.push(-1);
        int i=nums2.size()-1;
        while(i>=0){
            int element=nums2[i];
            while(st.size() > 1 && st.top() < element){
                st.pop();
            }
            ans[i]=st.top();
            st.push(element);
            i--;
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        for(int i=0;i<nums1.size();i++){
            int element=nums1[i];
            for(int j=0;j<nums2.size();j++){
                if(element==nums2[j]){
                    nums1[i]=ans[j];
                }
            }
        }
        return nums1;
    }
};
