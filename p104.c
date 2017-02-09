/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
int f(struct TreeNode *node, int x) {
    int result = x;
    if (node->left != NULL) result = f(node->left, x+1);
    if (node->right != NULL)
    {
        x = f(node->right, x+1);
        if (x > result) result = x;
    }
    return result;
}
 
int maxDepth(struct TreeNode* root) {
    if (!root) return 0;
    return f(root, 1);
}