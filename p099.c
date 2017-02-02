/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void recoverTree(struct TreeNode* root) {
    struct TreeNode *pred_output = NULL;
    struct TreeNode *r1 = NULL;
    struct TreeNode *r2 = NULL;
    struct TreeNode *cur = root;
    struct TreeNode *pred;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            if (pred_output != NULL && cur->val < pred_output->val)
            {
                r2 = cur;
                if (r1 == NULL)
                {
                    r1 = pred_output;
                }
            }
            pred_output = cur;
            cur = cur->right;
        }
        else
        {
            pred = cur->left;
            while (pred->right != NULL && pred->right != cur)
            {
                pred = pred->right;
            }
            if (pred->right == cur)
            {
                pred->right = NULL;
                if (pred_output != NULL && cur->val < pred_output->val)
                {
                    r2 = cur;
                    if (r1 == NULL)
                    {
                        r1 = pred_output;
                    }
                }
                pred_output = cur;
                cur = cur->right;
            }
            else
            {
                pred->right = cur;
                cur = cur->left;
            }
        }
    }
    r1->val ^= r2->val;
    r2->val ^= r1->val;
    r1->val ^= r2->val;
}