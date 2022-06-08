int c;
class Solution{
public:
    void inorder(Node *root,int l,int h)
    {
        if(!root) return;
        inorder(root->left,l,h);
        if(root->data>=l && root->data<=h) c++;
        inorder(root->right,l,h);
    }
    int getCount(Node *root, int l, int h)
    {
        if(!root) return 0;
     c=0;
     inorder(root,l,h);
     return c;
    }
};
