Node* segregate(Node *head) {
        
        // Add code here
        int count[3] = {0};
        Node* curr = head;
        while(curr!=NULL){
            count[curr->data]++;
            curr = curr->next;
        }
        curr = head;
        while(curr!=NULL){
            if(count[0]>0){
                curr->data = 0;
                count[0]--;
            }
            else if(count[1] > 0){
                curr->data = 1;
                count[1]--;
            }
            else{
                curr->data = 2;
            }
            curr = curr->next;
        }
        return head;
        
    }
