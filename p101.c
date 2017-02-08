/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
bool f(struct TreeNode *t1, struct TreeNode *t2)
{
    if ((!t1) && (!t2)) return true;
    if ((!t1) || (!t2) || t1->val != t2->val) return false;
    return f(t1->left, t2->right) && f(t1->right, t2->left);
}
 
bool isSymmetric(struct TreeNode* root) {
    if (!root) return true;
    return f(root->left, root->right);
}