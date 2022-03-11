/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL)
            return head;
        Node* temp=new Node(0);
        temp->next=head;
        Node*rhnext=NULL;
        //ListNode* temp=head;
        while(head){
            if(head->child){
               rhnext=head->next;
               head->next=flatten(head->child);
                head->child=NULL;
                head->next->prev=head;
                while(head->next)head=head->next;
                head->next=rhnext;
                if(rhnext)
                    rhnext->prev=head;
                
            }
            head=head->next;
        }
        return temp->next;
    }
};