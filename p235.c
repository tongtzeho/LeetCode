/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode *result = root;
    int minval = p->val;
    int maxval = q->val;
    if (minval > maxval)
    {
        minval ^= maxval;
        maxval ^= minval;
        minval ^= maxval;
    }
    while (result != NULL)
    {
        if (result->val >= minval && result->val <= maxval)
        {
            break;
        }
        else if (result->val > maxval)
        {
            result = result->left;
        }
        else
        {
            result = result->right;
        }
    }
    return result;
}