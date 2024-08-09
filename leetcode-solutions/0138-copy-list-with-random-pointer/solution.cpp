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
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        // cloned LL a->a'
        Node* it=head;
        while(it){
            Node*clonedNode=new Node(it->val);
            clonedNode->next=it->next;
            it->next=clonedNode;
            it=it->next->next;
        }
        // assign random links of a' with help of a->a'
        it=head;
        while(it){
            Node*clonedNode=it->next;
            clonedNode->random=it->random? it->random->next:NULL;
            it=it->next->next;
        }
        // detach a and a' (cloned and orignal LL)
        it=head;
        Node*clonedHead=it->next;
        while(it){
            Node*clonedNode=it->next;
            it->next=it->next->next;
            if(clonedNode->next){
                clonedNode->next=clonedNode->next->next;
            }
            it=it->next;
            }
            return clonedHead;
        
    }
};
