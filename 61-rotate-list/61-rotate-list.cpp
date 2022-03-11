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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return NULL;
        if(k==0)
            return head;
        int count=0;
        ListNode* temp=head;
        ListNode*res=head;
        while(head){
            count++;
            if(head->next==NULL && k>=1)
            {head->next=temp;
             break;}
             head=head->next;
        }
        
        int m=count-(k%count);
        
        while(res){
            //cout<<m<<" "<<res->val<<endl;
            if(m==1)
            {
                temp=res->next;
                res->next=NULL;
                break;
            }
            m--;
            res=res->next;
            
        }
        return temp;
    }
};