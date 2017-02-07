/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

inline int max(const int x, const int y)
{
    if (x > y) return x;
    return y;
}

void f(struct TreeNode *root, int *result)
{
    int s1 = 0, s2 = 0, tmp;
    if (root->left != NULL)
    {
        f(root->left, result);
        s1 = root->left->val;
    }
    if (root->right != NULL)
    {
        f(root->right, result);
        s2 = root->right->val;
    }
    tmp = max(root->val, max(s1+root->val, s2+root->val));
    (*result) = max((*result), max(s1+s2+root->val, tmp));
    root->val = tmp;
}
 
int maxPathSum(struct TreeNode* root) {
    int result = -2147483648;
    f(root, &result);
    return result;
}