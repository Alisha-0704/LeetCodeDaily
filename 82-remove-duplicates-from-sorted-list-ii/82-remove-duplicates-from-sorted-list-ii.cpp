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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=new ListNode(0,head);
        ListNode* previous=temp;
        
        while(head!=NULL){
            if(head->next!=NULL && head->val==head->next->val){
               while(head->next!=NULL && head->val==head->next->val){
                   head=head->next;
               }
                previous->next=head->next;
            }else{
                previous=previous->next;
            }
            head=head->next;
        }
        return temp->next;       
    }
};