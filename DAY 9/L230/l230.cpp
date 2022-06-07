class Solution {
public:
    vector<int> a;
    void inorder(TreeNode* root)
    {
        if(!root) return;
        inorder(root->left);
        a.push_back(root->val);
        inorder(root->right);
    }
   
    int kthSmallest(TreeNode* root, int k) 
    {
       
        
        inorder(root);
        int ans = a[k-1];
        return ans;  
    }
};
