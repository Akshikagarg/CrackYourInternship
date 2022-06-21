class Solution {
public:
    void reorderList(ListNode* head) {
        vector<int> arr;
     
        
        //storing all element in an array
        ListNode* temp = head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        
        /*
        now start tranversing in alternate manner 
         transversing the array from i=0 ,
         j to the end
         int n  = size of array-1
         i=0  j = n     head->val = arr[0];
         i= 1 , j=n-1   head->next->val = arr[j];
         simlary we will do until (i<=j)
         ...
        
        */
        temp = head;
        int i=0;
        int j = arr.size()-1;
        bool alternate = true;
        while(i<=j){
            if(alternate){
                temp->val = arr[i];
                temp = temp->next;
                i++;
                alternate =false;
    
            }else{
                temp->val = arr[j];
                temp = temp->next;
                j--;
                alternate = true;
            }
        } 
    }
};
