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
    ListNode* middleNode(ListNode* head) {
        if(!head)
            return nullptr;
        
        ListNode* prev=head;
        ListNode* next=head;
        
        while(prev && next->next){
            prev=prev->next;
            next=next->next->next;
            if(next==NULL)
                return prev;
        }
        return prev;
    }
};