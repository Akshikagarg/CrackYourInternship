Node *midPoint(Node* head){
   Node* slow = head;
   Node* fast = head->next;

   while(fast != NULL && fast->next != NULL){
       slow = slow->next;
       fast = fast->next->next;
   }

   return slow;
}


Node *reverseLL(Node *head)
{
   // This is iterative method to reverse a LL;
   if(head == NULL){
       return NULL;
   }
   
   Node *prev = NULL;
   Node *n = head->next;
   Node *curr = head;

   while (curr != NULL)
   {
       curr->next = prev;
       prev = curr;
       curr = n;

       if (curr == NULL || n == NULL)
       {
           return prev;
       }
       n = n->next;
   }

   return prev;
}

void reorderList(Node* head) {
   // Find mid point of LL
   // make two LL one from 0 to mid
   // and second is from mid->next to end;
   // reverse the second LL
   // and then iterate both at once
   
   Node* first = head;
   Node* mid = midPoint(head);
   Node* second = mid->next;
   mid->next = NULL;
   second = reverseLL(second);
   
   while(first != NULL && second != NULL){
       Node* firstNext = first->next;
       Node* secondNext = second->next;
       
       first->next = second;
       second->next = firstNext;
       first = firstNext;
       second = secondNext;
   }
   
}
