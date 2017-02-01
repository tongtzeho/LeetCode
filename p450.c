/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    struct TreeNode *node = root, *parent = root, *tmp;
    while (node != NULL)
    {
        if (key < node->val)
        {
            parent = node;
            node = node->left;
        }
        else if (key > node->val)
        {
            parent = node;
            node = node->right;
        }
        else
        {
            struct TreeNode *l = node->left, *r = node->right;
            if (l == NULL && r == NULL)
            {
                if (key < parent->val) parent->left = NULL;
                else if (key > parent->val) parent->right = NULL;
                else root = NULL;
                break;
            }
            else if (l != NULL)
            {
                struct TreeNode *lr = l;
                if (lr->right == NULL)
                {
                    if (key < parent->val) parent->left = l;
                    else if (key > parent->val) parent->right = l;
                    else root = l;
                    l->right = node->right;
                    break;
                }
                else
                {
                    while (lr->right->right != NULL)
                    {
                        lr = lr->right;
                    }
                    if (key < parent->val) parent->left = lr->right;
                    else if (key > parent->val) parent->right = lr->right;
                    else root = lr->right;
                    lr->right->right = node->right;
                    tmp = lr->right->left;
                    lr->right->left = node->left;
                    lr->right = tmp;
                    break;
                }
            }
            else
            {
                struct TreeNode *rl = r;
                if (rl->left == NULL)
                {
                    if (key < parent->val) parent->left = r;
                    else if (key > parent->val) parent->right = r;
                    else root = r;
                    r->left = node->left;
                    break;
                }
                else
                {
                    while (rl->left->left != NULL)
                    {
                        rl = rl->left;
                    }
                    if (key < parent->val) parent->left = rl->left;
                    else if (key > parent->val) parent->right = rl->left;
                    else root = rl->left;
                    rl->left->left = node->left;
                    tmp = rl->left->right;
                    rl->left->right = node->right;
                    rl->left = tmp;
                    break;
                }
            }
        }
    }
    return root;
}