/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
int f(struct TreeNode *root, int leftheight) {
    if (root == NULL) return 0;
    if (root->left == NULL) return 1;
    if (root->right == NULL) return 2;
    struct TreeNode *node = root->right;
    int height = 1;
    while (node != NULL)
    {
        height++;
        node = node->left;
    }
    if (height == leftheight)
    {
        return (1<<(height-1))+f(root->right, height-1);
    }
    else
    {
        return (1<<(height-1))+f(root->left, leftheight-1);
    }
}
 
int countNodes(struct TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL) return 1;
    int leftheight = 1;
    struct TreeNode *node = root->left;
    while (node != NULL)
    {
        leftheight++;
        node = node->left;
    }
    return f(root, leftheight);
}
