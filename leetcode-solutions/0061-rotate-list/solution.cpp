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
    int Findlen(ListNode*head){
        ListNode*temp=head;
        int len=0;
        while(temp){
            len++;
            temp=temp->next;
        }
        return len;
    }
    ListNode*helperRE(ListNode*&head,int k){
      if(k>Findlen(head) && Findlen(head)) k=k%Findlen(head);
      if(!head) return NULL;
      if(Findlen(head)==1)return head;
        if(k==0) return head;
        ListNode*prev=NULL;
        ListNode*last=head;
        while(last->next){
            prev=last;
            last=last->next;
        }
        last->next=head;
        prev->next=NULL;
        head=last;
        helperRE(head,k-1);
        return head;

    }
    ListNode* rotateRight(ListNode* head, int k) {
        return helperRE(head,k);
        
    }
};
