class Solution {
public:
    
    bool isSame(TreeNode *s,TreeNode *t)
    {
        if (!s && !t) return true;
        if (!s || !t) return false;
        if (s->val != t->val) return false;
        
        return isSame(s->left,t->right) && isSame(t->left, s->right);
        
    }
    bool isSymmetric(TreeNode* root) 
    {
    if(isSame(root->left,root->right)) 
    return 1;
    else
    return 0;
    }
};
