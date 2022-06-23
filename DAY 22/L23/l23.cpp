class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) 
    {

        // when list1 is empty return list2
        if (l1 == NULL)
            return l2;

        // when list2 is empty return list1
        if (l2 == NULL)
            return l1;

        // pointing l1 and l2 to smallest and greatest one
        if (l1->val > l2->val)
            swap(l1, l2);

        //head of resultant merged list
        ListNode *res = l1;

        while (l1 != NULL && l2 != NULL)
        {

            ListNode *temp = NULL;

            while (l1 != NULL && l1->val <= l2->val)
            {

                temp = l1; // storing last sorted node
                l1 = l1->next;
            }

            // link previous sorted node with next larger node in list2
            temp->next = l2;
            swap(l1, l2);
        }

        return res;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()==0)
            return NULL;

        ListNode *temp=lists[0];
        for(int i=1;i<lists.size();i++)
        {
            temp=mergeTwoLists(temp,lists[i]);
        }
        return temp;
    }
};
