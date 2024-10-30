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

    int findLen(ListNode*&head){
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }

     ListNode* reverseKGroupRE(ListNode* head, int k) {
        //we will use recurssion
        if(head==0 || head->next==0)return head;
        int len=findLen(head);
        if(len < k)return head;
        ListNode* prev=0;
        ListNode*curr=head;
        int position=0;
        ListNode*temp=curr->next;
        while(position < k){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            position++;
        }
        if(temp){
            ListNode*recAns=reverseKGroupRE(temp,k);
            head->next=recAns;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        //we will use recurssion

        return reverseKGroupRE(head,k);

    }
};
