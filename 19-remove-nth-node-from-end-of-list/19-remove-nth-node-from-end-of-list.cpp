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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return NULL;
        ListNode* res=head;
        ListNode*temp=head;
        int count=0;
        while(temp)
        {
            count++;
            temp=temp->next;

        }
        int m=count-n+1;
        if(m==1)
            return head->next;
        
        while(head && head->next){
            if(m==2)
            head->next=head->next->next;
            m--;
            head=head->next;
        }
        return res;
    }
};