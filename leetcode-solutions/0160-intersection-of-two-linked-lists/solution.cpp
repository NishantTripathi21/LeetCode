/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int findLen(ListNode*head){
        ListNode*temp=head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA=findLen(headA);
        int sizeB=findLen(headB);
        int diff=sizeA>=sizeB?sizeA-sizeB:sizeB-sizeA;
        if(sizeA<sizeB){
            for(int i=0;i<diff;i++){
                headB=headB->next;
            }
        }
        if(sizeA>sizeB){
            for(int i=0;i<diff;i++){
                headA=headA->next;
            }
        }
        if(headA==headB)
                {return headA;}
        while(headA!=headB || (headA==NULL || headB==NULL)){
            headA=headA->next;
            headB=headB->next;
            if(headA==headB)return headA;
        }
        return NULL;

        
    }
};
