bool isBST(Node* root, int ub,int lb){
       if(!root)
           return true;
       if(root->data>=ub||root->data<=lb){
           return false;
       }
       else 
       return isBST(root->left,root->data,lb)&&isBST(root->right,ub,root->data);
       
   }
   
   int nodeCount(Node *root){
       if(!root)
           return 0;
       else    
       return 1+nodeCount(root->left)+nodeCount(root->right);
   }
   
   int largestBst(Node *root)
   {
       if(!root)
       return 0;
    if(isBST(root,INT_MAX,INT_MIN)){
        return nodeCount(root);
    }
    else
    return max(largestBst(root->left),largestBst(root->right));
   }
