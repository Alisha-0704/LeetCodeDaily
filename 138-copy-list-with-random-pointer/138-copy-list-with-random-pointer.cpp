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
        if(!head)
            return NULL;
        Node* res=new Node(0);
        Node* temp2=res;
        Node* fin=res;
        unordered_map<Node*,Node*>m;
        Node* temp=head;
        while(head){
            res->val=head->val;
            m[head]=res;
            if(head->next==NULL)
            res->next=NULL;
            else
            res->next=new Node(0);
            res=res->next;
            head=head->next; 
        }
        
        while(temp){
            temp2->random=m[temp->random]; 
            temp=temp->next;
            temp2=temp2->next;
        }
        
        return fin;
    }
};