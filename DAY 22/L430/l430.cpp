class Solution {
public:
vector<Node*> temp;
void bfs(Node* head)
{
if(!head) return;
temp.push_back(head);

    bfs(head->child);
    bfs(head->next);
}
Node* flatten(Node* head) {
    if(!head) return head;
    bfs(head);
    int i=0;
    head=temp[i];
    temp[i]->prev=NULL;
    for(i;i<temp.size()-1;i++)
    {
        temp[i]->next=temp[i+1];
        temp[i+1]->prev=temp[i];
        temp[i]->child=NULL;
    }
    temp[i]->next=NULL;
    temp[i]->child=NULL;
    return head;
}
};

