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
        if(head==NULL)return head;
        if(head->next==NULL)return head;
        int len=findLen(head);
        if(len <k)return head;

        //1 case solution
        ListNode*prev=NULL;
        ListNode*curr=head;
        int position=0;
        ListNode*nextNode=curr->next;
        while(position<k ){
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
            position++;
        }
    
        ListNode* recurKaAns=NULL;
        if(nextNode!=NULL){
            recurKaAns=reverseKGroup(nextNode,k);
            head->next=recurKaAns;
        }
        return prev;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        //we will use recurssion

        return reverseKGroupRE(head,k);

    }
};
