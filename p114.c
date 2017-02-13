/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    if (!root) return;
    struct TreeNode *cur = root;
    struct TreeNode *prev = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode *tmp;
    while (cur != NULL)
    {
        if (cur->left != NULL)
        {
            tmp = cur->left;
            while (tmp->right != NULL && tmp->right != cur)
            {
                tmp = tmp->right;
            }
            if (tmp->right == NULL)
            {
                tmp->right = cur;
                prev->left = cur;
                prev = cur;
                cur = cur->left;
            }
            else
            {
                cur = cur->right;
            }
        }
        else
        {
            prev->left = cur;
            prev = cur;
            cur = cur->right;
        }
    }
    cur = root;
    while (cur != NULL)
    {
        cur->right = cur->left;
        tmp = cur;
        cur = cur->right;
        tmp->left = NULL;
    }
}
