class Solution{
public:
   Node* divide(int N, Node *head){
       // code here
       Node* eve = new Node(-1);
       Node* evechal = eve;
       Node* odd = new Node(-1);
       Node* oddchal = odd;
       while(head)
       {
           if(head->data%2 == 0)
           {
               evechal->next = head;
               evechal = evechal->next;
           }
           else
           {
               oddchal->next = head;
               oddchal = oddchal->next;
           }
           head = head->next;
       }
       oddchal->next = NULL;
       evechal->next = odd->next;
       return eve->next;
   }
};
