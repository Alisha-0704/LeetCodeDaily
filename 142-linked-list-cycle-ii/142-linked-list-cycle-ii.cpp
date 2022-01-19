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
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return nullptr;
    if(!head->next){
            return NULL;
        }
        ListNode* left=head->next;
        ListNode* right=head->next->next;
        
        while(right && right->next && right != left){
            left=left->next;
            right=right->next->next;
        }
        if(!right || !right->next){
            return nullptr;
        }
        right = head;
        while(right != left){
            right = right->next;
            left = left->next;
        }
        return left;
        
    }
};