/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
bool f(struct TreeNode *node, const int sum, const int cursum)
{
    int tmp = cursum+node->val;
    if (node->left != NULL)
    {
        if (f(node->left, sum, tmp)) return true;
        if (node->right != NULL)
        {
            if (f(node->right, sum, tmp)) return true;
        }
    }
    else if (node->right != NULL)
    {
        if (f(node->right, sum, tmp)) return true;
    }
    else
    {
        return tmp == sum;
    }
    return false;
}
 
bool hasPathSum(struct TreeNode* root, int sum) {
    if (!root) return false;
    return f(root, sum, 0);
}
