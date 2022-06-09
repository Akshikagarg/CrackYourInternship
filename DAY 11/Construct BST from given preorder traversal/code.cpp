struct Node *ct(int n,int &i, int pre[], char preLN[]){
   if(i>=n) return NULL;
   Node* root = new Node(pre[i]);
   
   if(preLN[i]=='N'){
       root->left = ct(n,++i,pre,preLN);
       root->right = ct(n,++i,pre,preLN);
   }
   
   return root;
}


struct Node *constructTree(int n, int pre[], char preLN[])
{
   // Code here
   int i=0;
   return ct(n,i,pre,preLN);
}
