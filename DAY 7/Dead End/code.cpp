void check(Node* root, int min, int max, bool &ans)
{
   if(!root) return;
   check(root->left, min,root->data-1,ans);
   if(min == max) ans=true;
   check(root->right,root->data+1,max,ans);
}

bool isDeadEnd(Node *root)
{
   if(!root) return 0;
   bool ans=0;
   check(root,1,INT_MAX,ans);
   
   return ans;
}
