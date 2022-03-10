class Solution {
public:
 ListNode* merge(ListNode* l1, ListNode* l2){
        if(l1==NULL) 
            return l2; 
            
        if(l2==NULL) 
            return l1;
            
        ListNode*temp; 
            if(l1->val<=l2->val){
                temp=l1;  
                temp->next=merge(l1->next,l2);
            }
            else{
                temp=l2; 
                temp->next=merge(l1, l2 -> next);
            }
        return temp;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  		
        if(list1 == NULL && list2 == NULL) 
            return NULL;
            
        if(list1 == NULL) 
            return list2;
            
        if(list2 == NULL) 
            return list1;

        return merge(list1,list2);    
    }
};