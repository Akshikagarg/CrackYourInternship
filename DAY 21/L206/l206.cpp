class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* next=NULL;
        ListNode* pre=NULL;
         while(head!=NULL){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
        
    }
};
