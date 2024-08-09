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
    int FindLen(ListNode*&head){
        ListNode*temp=head;
        int len=0;
        while(temp){
            temp=temp->next;
            len++;
        }
        return len;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        //kth from end means totalNodes-k+1 from starting
        if(!head) return NULL;
        int len=FindLen(head);
        int last=len-k+1;
        ListNode*temp1=head;
        ListNode*temp2=head;
        while(k!=1){
            temp1=temp1->next;
            k--;
        }
        while(last!=1){
            temp2=temp2->next;
            last--;
        }
        swap(temp1->val,temp2->val);
        return head;
    }
};
