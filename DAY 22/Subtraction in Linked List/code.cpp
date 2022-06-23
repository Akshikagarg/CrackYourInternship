Node*rev(Node*head){
   Node*c = head;
   Node*p = NULL;
   Node*n = NULL;
   while(c){
       n = c->next;
       c->next = p;
       p = c;
       c = n;
   }
   head = p;
   return head;
}

Node*sub(Node*a,Node*b){
   //reverse the lists and try rememnering the basics of subtraction and ll addition 
   a = rev(a);
   b = rev(b);
   Node*l2 = b;
   Node*l1 = a;
   Node*ans = new Node(0);
   Node*t = ans;
   while(l1->next and l2->next){
       l1 = l1->next;
       l2 = l2->next;
   }
   while(l1->next){
       Node*n = new Node(0);
       l2->next = n;
       l2 = l2->next;
       l1 = l1->next;
   }
   
   int r = 0; //remainder 
   
   //make them head again
   
   l1 = a;
   l2 = b;
   
   while(l1 and l2){
       int x = (l1->data)-(l2->data);
       if(x-r>=0){
           Node*n = new Node(x-r);
           t->next = n;
           t = t->next;
           r = 0;
       }
       else{
           int z = (x-r+10);
           Node*n = new Node(z);
           t->next = n;
           t = t->next;
           r = 1;
       }
       l1 = l1->next;
       l2 = l2->next;
   }
   Node*res = ans->next;
   
   res = rev(res);
   if(res->data==0) return res->next; //remove any front 0
   
   return res;
}


Node* subLinkedList(Node* l1, Node* l2)
{
   //Your code here
   
   //Check weather l1 or l2 is 0 or not
   if(l1->next == NULL and l1->data==0) return l2;
   if(l2->next == NULL and l2->data==0) return l1;
   
   //remove the front 0s
   while(l1->data==0) l1 = l1->next;
   while(l2->data==0) l2 = l2->next;
   Node*t1 = l1;
   Node*t2 = l2;
   
   //check the sizes of l1 and l2 and store it in a and b respectively
   int a = 0;
   while(t1){
       a++;
       t1 = t1->next;
   }
   int b = 0;
   while(t2){
       b++;
       t2 = t2->next;
   }
   
   //compare the sizes and see if you need to perform l1-l2 or l2-l1 to keep the result positive
   
   if(a>b){
       return sub(l1,l2);
   }
   else if(a<b){
       return sub(l2,l1);
   }
   else{ //if bothe have same sizes then check the first bigger no of the two to compare the greater number
       while(l1 and l2){
           if(l1->data>l2->data){
               return sub(l1,l2);
           }
           else if(l1->data<l2->data){
               return sub(l2,l1);
           }
           else{
               l1 = l1->next;
               l2 = l2->next;
           }
       } 
       //if you dont find any no greater this means that they are equal so return 0->NULL
       Node*n = new Node(0);
       n->next = NULL;
       return n;
   }
   return NULL; //optional
   
}

 
