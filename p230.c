/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
struct TreeNode* f(struct TreeNode *root, int k, int *count) {
    struct TreeNode *result = NULL;
    int cntl = 0;
    int cntr = 0;
    if (root->left != NULL)
    {
        result = f(root->left, k, &cntl);
        if (result != NULL) return result;
    }
    if (k == cntl+1)
    {
        result = root;
        return result;
    }
    if (root->right != NULL)
    {
        result = f(root->right, k-cntl-1, &cntr);
        if (result != NULL) return result;
    }
    (*count) = cntl+1+cntr;
    return NULL;
}
 
int kthSmallest(struct TreeNode* root, int k) {
    int count = 0;
    struct TreeNode *result = f(root, k, &count);
    return result->val;
}
