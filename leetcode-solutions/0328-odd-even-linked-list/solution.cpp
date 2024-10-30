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
    ListNode* helper(ListNode* head){
        if(!head)return 0;
        ListNode* curr=head;
        ListNode* prev=0;
        ListNode* odd=new ListNode(-1);
        ListNode*head2=odd;
        int count=1;
        while(curr){
            prev=curr;
            if(curr->next){
                curr=curr->next;
            }
            else break;
            count++;
            
            if(count % 2==0){
                prev->next=curr->next;
                if(!odd){
                    odd=curr;
                }
                else if(odd){
                    odd->next=curr;
                    odd=odd->next;
                    odd->next=0;
                }
            }
            curr=prev->next;
            count++;
        }
        head2=head2->next;
        prev->next=head2;
        return head;
    }
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode*odd=head;
        ListNode*even=head->next;
        ListNode*head2=even;
        while(odd->next!=NULL && even->next!=NULL){
            odd->next=even->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next;
        }
        odd->next=head2;
        return head;
        //return helper(head);
        
    }
};
