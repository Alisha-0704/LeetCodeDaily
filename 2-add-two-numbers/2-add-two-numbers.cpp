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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int count=0;
        ListNode* res=l1;
        ListNode* prev;
        
        while(l1 || l2 || count){
           int sum=0;
            if(l1!=NULL){
                prev=l1;
                sum+=l1->val;
            }
            if(l2!=NULL){
                sum+=l2->val;
            }
            sum+=count;
            if(l1){
                l1->val=sum%10;
                
            }
             else
            if(l1==NULL){
                prev->next=new ListNode(sum%10);
                prev=prev->next;
            }
            if(l1)
            l1=l1->next;
            if(l2)
            l2=l2->next;
            count=sum/10;
        }
        return res;
  
    }
};