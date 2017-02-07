/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
bool f(struct TreeNode *root, struct TreeNode *min, struct TreeNode *max)
{
    return (root == NULL) || ((root->left == NULL || (root->left->val < root->val && (min == NULL || root->left->val > min->val) && f(root->left, min, root))) && (root->right == NULL || (root->right->val > root->val && (max == NULL || root->right->val < max->val) && f(root->right, root, max))));
}
 
bool isValidBST(struct TreeNode* root) {
    struct TreeNode *min = NULL, *max = NULL;
    return f(root, min, max);
}