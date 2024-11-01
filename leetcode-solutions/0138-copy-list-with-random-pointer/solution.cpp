/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* usingMapping(Node* head){
        unordered_map<Node*,Node*>oldToNew;//stroe old to new map
        Node*newHead= new Node(-1);
        Node* head2=newHead;
        Node*curr=head;
        while(curr){
            head2->next=new Node(curr->val);
            oldToNew[curr]=head2->next;
            head2=head2->next;
            curr=curr->next;
        }
        newHead= newHead->next;
        curr=head;
        head2=newHead;
        while(curr && head2){
            if(curr->random){
                head2->random=oldToNew[curr->random];
            }
            curr=curr->next;
            head2=head2->next;
        }
        return newHead;
    }
    Node* copyRandomList(Node* head) {
        // if(!head) return NULL;
        // // cloned LL a->a'
        // Node* it=head;
        // while(it){
        //     Node*clonedNode=new Node(it->val);
        //     clonedNode->next=it->next;
        //     it->next=clonedNode;
        //     it=it->next->next;
        // }
        // // assign random links of a' with help of a->a'
        // it=head;
        // while(it){
        //     Node*clonedNode=it->next;
        //     clonedNode->random=it->random? it->random->next:NULL;
        //     it=it->next->next;
        // }
        // // detach a and a' (cloned and orignal LL)
        // it=head;
        // Node*clonedHead=it->next;
        // while(it){
        //     Node*clonedNode=it->next;
        //     it->next=it->next->next;
        //     if(clonedNode->next){
        //         clonedNode->next=clonedNode->next->next;
        //     }
        //     it=it->next;
        //     }
        //     return clonedHead;
        return usingMapping(head);
    }
};
