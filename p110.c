/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
int getDepth(struct TreeNode *root) {
    int d1 = 0, d2 = 0;
    if (root->left != NULL) d1 = getDepth(root->left);
    if (d1 < 0) return -1;
    if (root->right != NULL) d2 = getDepth(root->right);
    if (d2 < 0 || d1-d2 > 1 || d2-d1 > 1) return -1;
    if (d1 >= d2) return 1+d1;
    return 1+d2;
} 
 
bool isBalanced(struct TreeNode* root) {
    if (!root) return true;
    int d1 = 0, d2 = 0;
    if (root->left != NULL) d1 = getDepth(root->left);
    if (d1 < 0) return false;
    if (root->right != NULL) d2 = getDepth(root->right);
    return d2 >= 0 && d1-d2 <= 1 && d1-d2 >= -1;
}