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
    void insertAtHead(ListNode*&head,ListNode*newNode){
        newNode->next=head;
        head=newNode;
    }
    void DoubleRE(ListNode*&head,int &carry){
        if(!head)return;
        DoubleRE(head->next,carry);
        int pro=head->val*2;
        int digit=pro%10 +carry;
        carry=pro/10;
        head->val=digit;
    }

    ListNode* doubleIt(ListNode* head) {
        int carry=0;
        DoubleRE(head,carry);
        if(carry){
            ListNode*newNode=new ListNode(carry);
            insertAtHead(head,newNode);
        }
        return head;
        
    }
};
