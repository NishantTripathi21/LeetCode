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
 class compare{
        public:
        bool operator()(ListNode* a,ListNode*b){
        return a->val > b->val;
    }
    };
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return 0;
        priority_queue<ListNode*,vector<ListNode*>,compare>q;
        //push first elements of every List
        for(int i=0;i<lists.size();i++){
            if(lists[i]){
                q.push(lists[i]);
            }
        }
        ListNode*head=0;
        ListNode*tail=0;
        //process next elements;
        while(!q.empty()){
            ListNode* temp=q.top();
            q.pop();
            if(!head){
                head=temp;
                tail=temp;
            }
            else{
                tail->next=temp;
                tail=tail->next;
            }
            if(temp->next){
                q.push(temp->next);
            }
        }
        return head;
    }
};
