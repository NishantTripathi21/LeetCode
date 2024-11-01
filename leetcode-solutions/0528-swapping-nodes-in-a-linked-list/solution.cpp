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
 #include<functional>
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
    ListNode*changingLinks(ListNode* &head,int k){
        //this question has many cases:
        if(!head || !head->next)return head;
        int len=FindLen(head);
        int lpos=k;
        int rpos=len-k+1;
        if(lpos==rpos)return head;
        //if leftPosition is greater than rightPosiiton
        if(lpos > rpos)swap(lpos,rpos);
        if(len==2){
            //when size of linkedList is 2, and k=1 or 2
            auto temp=head->next;
            temp->next=head;
            head->next=nullptr;
            head=temp;
            return head;
        }
        //upto line 60, code for traversal 
        int last=rpos; 
        auto startNode=head;
        auto nextOfStartNode=startNode->next;
        ListNode*prevOfStartNode=0;
        auto endNode=head;
        auto nextOfEndNode=startNode->next;
        ListNode*prevOfEndNode=0;
        k=lpos;
        cout<<"last: "<<last<<" k: "<<k<<endl;
        while(k!=1){
            prevOfStartNode=startNode;
            startNode=nextOfStartNode;
            nextOfStartNode=nextOfStartNode->next;
            k--;
         }
         while(last != 1){
            prevOfEndNode=endNode;
            endNode=nextOfEndNode;
            nextOfEndNode=nextOfEndNode->next;
            last--;
        }
        cout<<"rpos: "<<rpos<<" lpos: "<<lpos<<endl;
        if(lpos==1){
            //when k==1 or k==length of linked list, head gets changed
            endNode->next=startNode->next;
            prevOfEndNode->next=startNode;
            startNode->next=nextOfEndNode;
            head= endNode;
            return head;
        }
        if(rpos-lpos==1){
            // when left position and right position are adjacent
            prevOfStartNode->next=endNode;
            endNode->next=startNode;
            startNode->next=nextOfEndNode;
            return head;
        }
        else{
            //when leftPosition and rightposition has more than 1 gap
            cout<<"startNode: "<<prevOfStartNode->val<<" "<<startNode->val<<" "<<nextOfStartNode->val<<endl;
            cout<<"end node : "<<prevOfEndNode->val<<" "<<endNode->val<<" "<<nextOfEndNode->val<<endl;
            prevOfStartNode->next=endNode;
            endNode->next=nextOfStartNode;
            startNode->next=nextOfEndNode;
            prevOfEndNode->next=startNode;
        }
        return head;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        //one method is by swapping node values;
        //other method is changing links -> invloves multiple cases,which must be handled properly
        // and seperately->makes it hard level question
        return changingLinks(head,k);
    }
};
