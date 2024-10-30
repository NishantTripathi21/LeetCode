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
    bool hasCycleM2(ListNode* head){
        ListNode* temp=head;
        map<ListNode*, bool>table;
        while(temp!=NULL){
            if(table[temp]==false){
                table[temp]=true;
            }
            else {
                return true;
            }
            temp=temp->next;
        }
        return false;
    }

    bool hasCycle(ListNode *head) {
        //we can solve this question by using map and tortois method
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast){
            fast=fast->next;
            if(fast){
                fast=fast->next;
                slow=slow->next;
            }
            if(slow==fast)return true;
        }
        return false;
       // return hasCycleM2(head);

    }
};
