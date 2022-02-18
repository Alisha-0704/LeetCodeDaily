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
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return nullptr;
        
        ListNode* prev=nullptr;
        ListNode* nex=nullptr;
        ListNode* res=head;
        while(res){
            nex=res->next;
            res->next=prev;
            prev=res;
            res=nex;
        }
        
        return prev;
    }
};