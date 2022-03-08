/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        int p=INT_MIN;
        while(head){
            if(head->val==p)
                return true;
            head->val=p;
            head=head->next;
        }
        return false;
    }
};