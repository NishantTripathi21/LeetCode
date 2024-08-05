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
    ListNode* reverseList(ListNode* head) {
        ListNode*prev=NULL;
        ListNode*curr=head;
        while(curr!=NULL){
            ListNode* nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        return prev;
    }
    ListNode* middleNode(ListNode* head) {
        //slow fast approach,tortouis approach
        ListNode* slow=head;
        ListNode*fast=head;
        while(fast->next!=NULL){
            fast=fast->next;
            if(fast->next!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        return slow;
        
    }

    bool compareList(ListNode* head,ListNode* head2){
        while(head!=NULL && head2!=NULL){
            if(head->val != head2->val){
                return false;
            }
            else{
                head=head->next;
                head2=head2->next;
            }
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        // two methods-one is to reverse whole linked list and compare it with given LL
        // seecond mthod is to get the middle of the LL and reverse the other half of list
        // and compare both
        ListNode* midnode=middleNode(head);
        ListNode* head2=midnode->next;
        midnode->next=NULL;
        head2=reverseList(head2);
        bool ans=compareList(head,head2);

        return ans;
    }
};
