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
    ListNode* reverse(ListNode* head, int k){
        int m=1;
        if(!head)
            return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr->next!=NULL && m<k){
            curr=curr->next;
            m++;
        }
         if(m<k){
            return head;
        }
        ListNode* tempval=curr->next;
        curr->next=NULL;
        curr= head;
        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        ListNode* res=reverse(tempval,k);
        head->next= res;
        return prev;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
       if(!head)
           return  head;
        //ListNode*temp=head;
        return reverse(head,k);
        //return temp;
        
    }
};