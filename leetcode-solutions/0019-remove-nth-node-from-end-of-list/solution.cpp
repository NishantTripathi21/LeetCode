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
        ListNode*temp=head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }
    void deleteNode(ListNode*&head,int position){
        if(head==NULL)return;
        int len=findLen(head);
        //single element LL
        if(head->next==NULL){
            delete head;
            head=NULL;
        }
        else if(position==1){
            //delete from head
            ListNode* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;

        }
        else if(position==len){
            ListNode* temp=head;
            ListNode* temp1=temp->next;
            while(temp1->next!=NULL){
                temp=temp->next;
                temp1=temp1->next;
            }
            temp->next=NULL;

           delete temp1;

        }
    
        //delete from any pos
        else{
            ListNode*prev=NULL;
            ListNode*curr=head;
            while(position!=1){
                position--;
                prev=curr;
                curr=curr->next;
            }
            //prev ke next me curr ka next add karoo;
            prev->next=curr->next;
            //node isolate krdo
            curr->next=NULL;
            //delete node;
            delete curr;

        }

    }
    //method 2 optimised one
    ListNode* helper(ListNode*head,int n){
        auto fast=head;
        auto slow=head;
        for(int i=1;i<=n;i++){
            fast=fast->next;
        }
        if(!fast)return head->next;
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        auto deleteNode=slow->next;
        slow->next=deleteNode->next;
        deleteNode->next=0;
        return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // int len=findLen(head);
        // int position=len-n+1;
        // deleteNode(head,position);
        // return head;
        return helper(head,n);
    }
};
