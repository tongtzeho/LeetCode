/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
int sum;
 
void f(struct TreeNode *node, const int x)
{
    int val = (x<<3)+(x<<1)+node->val;
    if (node->left != NULL)
    {
        f(node->left, val);
        if (node->right != NULL)
        {
            f(node->right, val);
        }
    }
    else if (node->right != NULL)
    {
        f(node->right, val);
    }
    else
    {
        sum += val;
    }
}
 
int sumNumbers(struct TreeNode* root) {
    if (!root) return 0;
    sum = 0;
    f(root, 0);
    return sum;
}
