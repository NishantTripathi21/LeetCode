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
        // int carry=0;
        // DoubleRE(head,carry);
        // if(carry){
        //     ListNode*newNode=new ListNode(carry);
        //     insertAtHead(head,newNode);
        // }
        // return head;
        int carry=0;
        helper(head,carry);
        if(carry != 0){
            ListNode* newNode=new ListNode(carry);
            newNode->next=head;
            head=newNode;
        }
        return head;
        
    }
    void helper(ListNode* &head,int &carry){
        if(!head)return ;
        helper(head->next,carry);
        int totalSum=head->val * 2 + carry;
        int digit= totalSum % 10;
        carry= totalSum / 10;
        head->val= digit;
    }
};
