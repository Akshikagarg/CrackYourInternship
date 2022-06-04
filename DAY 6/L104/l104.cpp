class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int x=0,y=0;
        x=maxDepth(root->left);
        y=maxDepth(root->right);
        if (x>y) return x+1;
        return y+1;
    }
};
