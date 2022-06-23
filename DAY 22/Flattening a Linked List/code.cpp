Node* mergeSortedList(Node* head1,Node* head2)
{
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    Node* temp=new Node(0);
    Node* res=temp;

    while(head1!=NULL and head2!=NULL)
    {
    	if(head1->data<head2->data)
    	{
    	temp->bottom=head1;
    	head1=head1->bottom;
 	    temp=temp->bottom;
    	}
    	else
    	{
		temp->bottom=head2;
		head2=head2->bottom;
	    temp=temp->bottom;
        }    
    }
    if(head1!=NULL)
    temp->bottom=head1;
    else
    temp->bottom=head2;
      
    return res->bottom;
}

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   // Your code here
   if(root==NULL or root->next==NULL) return root;
   Node* temp=new Node(0);
   temp->bottom=root;
   while(root->next!=NULL)
   {
       temp->bottom=mergeSortedList(temp->bottom,root->next);
       root=root->next;
   }
   return temp->bottom;
}

