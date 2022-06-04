class Solution {
private:
    int ans = 0;
public:
    
    void findSum(TreeNode* root, bool isLeft)
    {
        // In the further resursive calls, anytime we node can be null so check it first.
        if(!root) return;
        // Checking if node is a leaf node
        if(!root->left && !root->right && isLeft){
            ans += root->val;
        }
        // Check left node
        findSum(root->left, true);
        // Check right node
        findSum(root->right, false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        // No nodes
        if(!root) return ans;
        // Single node
        if(!root->left && !root->right) return ans;
        // more than one node
        findSum(root, true);
        return ans;
    }
};
