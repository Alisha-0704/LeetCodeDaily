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
    ListNode* reverse(ListNode* temp){
        if(!temp || !temp->next)
            return temp;
        
        ListNode* res=reverse(temp->next);
        temp->next->next=temp;
        temp->next=NULL;
        return res;
    }
    bool isPalindrome(ListNode* head) {
       
       ListNode* slow=head;
       ListNode* fast= head;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *cur=slow;
        ListNode *tnext=NULL;
        ListNode *tprev=NULL;
        while(cur){
            tnext=cur->next;
            cur->next=tprev;
            tprev=cur;
            cur=tnext;
        }
        
        while(tprev && head){
            if(head->val!=tprev->val)
                return false;
            tprev=tprev->next;
            head=head->next;
        }
        return true;
    }
};