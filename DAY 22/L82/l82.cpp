class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = head, *prev = NULL;
        
        if(head == NULL)
            return NULL;
        
        while(temp!=NULL){          
            if(temp->next!=NULL && temp->val == temp->next->val)
            {
                while(temp->next!=NULL && temp->val == temp->next->val)
                temp = temp->next;
            
                if(prev!=NULL)
                    prev->next = temp->next;
                else
                    head = temp->next;
                temp = temp->next;
            }
            else{
                prev = temp;
                temp = temp->next;
            } 
        }
        
        return head;
    }
};
