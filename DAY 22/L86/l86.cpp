 ListNode* partition(ListNode* head, int x) {
        
        ListNode* temp = head;
        
        vector<int> v, k;
        
        while(temp != NULL)
        {
            if(temp->val < x)
            {
               v.push_back(temp->val);
            }
            else{
                k.push_back(temp->val);
            }
            
            temp = temp->next;
        }
        
        for(int i=0; i<k.size(); i++)
        {
            v.push_back(k[i]);
        }
        
        ListNode prehead(0), *p = &prehead;
        
        for(int i=0; i<v.size(); i++)
        {
            p->next = new ListNode(v[i]);
            p = p->next;
        }
        
        return prehead.next;
    }
