class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* node = root -> left;
        root -> left = invertTree(root -> right);
        root -> right = invertTree(node);
        return root;
    }
};
