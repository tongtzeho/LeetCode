/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (!p) return !q;
    else return q != NULL && p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}