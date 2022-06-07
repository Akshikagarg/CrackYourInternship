 bool hasPath(Node *root, vector<int> &res,int x)
   {
      if(!root) 
       return false;
      
      res.push_back(root->data);
      
      if(root->data==x)
       return true;
   
    if(hasPath(root->left,res,x)||hasPath(root->right,res,x))
      return true;
     
     res.pop_back();
     return false;
       
   }
   int findDist(Node* root, int a, int b) {
       //find  LCA of two nodes then distance is sum  of their respective distance to LCA
       if(!root)
         return 0;
       if(root->data ==a && root->data==b)
        return 0;
       vector<int> v1;//path to node a
       vector<int> v2; //path to node b
       
       hasPath(root,v1,a);
       hasPath(root,v2,b);
       int m1=v1.size();
       int m2=v2.size();
       int i=0,j=0;
       
       while(v1[i]==v2[j])
       {
           i++,j++;
       }
       
       //m1-i: distance from a to LCA(a,b)
       //m2-j: //distance from b to LCA(a,b)
       return (m1-i)+(m2-j);
   }
