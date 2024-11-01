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
    void sanitiseMap(unordered_map<int,ListNode*>&mp,ListNode*curr,int csum){
        int temp=csum;
        while(true){
            temp+=curr->val;
            if(temp==csum)break;
            mp.erase(temp);
            curr=curr->next;
        }
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head)return 0; 
        //map to track previous nodes sum corresponidng to current node
        unordered_map<int,ListNode*>mp;
        ListNode* curr=head;
        int csum=0;//sum of elements
        while(curr){
            csum+=curr->val;
            //if by anyhow currentSum equals to zero, that means sum of all nodes including curr Node is zero,remove
            //everyElement upto current node and move head, and clear map
            if(csum==0){
                head=curr->next;
                mp.clear();
            }
            //if current sum is already present, means sum of every nodes between previous sum and current sum is zero
            else if(mp.find(csum) != mp.end()){
                auto temp=mp[csum];
                //remove entries 
                sanitiseMap(mp,temp->next,csum);
                temp->next=curr->next;
            }
            else{
                mp[csum]=curr;
            }
            curr=curr->next;
        }
        return head;
    }
};
