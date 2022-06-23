class Solution{
  public:
  
    Node* middleNode(Node* node){
        Node* slow = node;
        Node* fast = node->next;
        
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    Node* merge(Node* A, Node* B){
        Node* head = new Node(-1);
        Node* temp = head;
        
        while(true){
            if(A and B){
                if(A->data < B->data){
                    temp->next = new Node(A->data);
                    A = A->next;
                    temp = temp->next;
                }
                else{
                    temp->next = new Node(B->data);
                    B = B->next;
                    temp = temp->next;
                }
            }
            else if(A){
                temp->next = new Node(A->data);
                A = A->next;
                temp = temp->next;
            }
            else if(B){
                temp->next = new Node(B->data);
                B = B->next;
                temp = temp->next;
            }
            else{
                break;
            }
        }
        
        return head->next;
    }
  
  
    Node* mergeSort(Node* head) {
        if(! head){
            return head;
        }
        if(!head->next){
            return head;
        }
        
        Node* mid = middleNode(head);
        Node* left = head;
        Node* right = mid->next;
        mid->next = NULL;
        
        Node* A = mergeSort(left);
        Node* B = mergeSort(right);
        
        Node* C = merge(A, B);
        
        return C;
    }
};
