/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ll;
        while(head){
            ll.push_back(head->val);
            head=head->next;
        }
        vector<int>ans(ll.size());
        stack<int>st;
        st.push(0);
        for(int i=ll.size()-1;i>=0;i--){
            int curr=ll[i];
            while(st.top()<=curr && st.top()!=0){
                st.pop();
            }
            if(!st.empty() && st.top()>curr){
                ans[i]=st.top();
                st.push(curr);
            }
            else{
                ans[i]=0;
                st.push(curr);
            }

        }
        return ans;
        
    }
};
