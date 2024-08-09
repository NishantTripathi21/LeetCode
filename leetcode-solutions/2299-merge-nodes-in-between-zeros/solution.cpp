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
    ListNode* mergeNodes(ListNode* head) {
        if(!head)return NULL;
        ListNode*slow=head;
        ListNode*fast=head->next;
        ListNode*prev=NULL ;
        int sum=0;
        while(fast){
            if(fast->val!=0){
                sum+=fast->val;
            }
            else{
            slow->val=sum; 
            prev=slow;
            slow=slow->next;
            sum=0;
            }
            fast=fast->next;
        }
        //deleting old list
        ListNode*temp=prev->next;
        prev->next=NULL;
        while(temp){
            ListNode*nx=temp->next;
            delete temp;
            temp=nx;
        }
        return head;
    }
};
