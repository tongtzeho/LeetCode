/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if (!root) return 0;
    int result = 0;
    struct TreeNode **oldarr = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    oldarr[0] = root;
    struct TreeNode **newarr = NULL;
    int i, oldsize = 1, newsize = 0;
    while (true)
    {
        newsize = 0;
        result++;
        newarr = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*(oldsize<<1));
        for (i = 0; i < oldsize; i++)
        {
            if (oldarr[i]->left != NULL) 
            {
                newarr[newsize++] = oldarr[i]->left;
                if (oldarr[i]->right != NULL) newarr[newsize++] = oldarr[i]->right;
            }
            else if (oldarr[i]->right != NULL) newarr[newsize++] = oldarr[i]->right;
            else
            {
                return result;
            }
        }
        oldarr = newarr;
        oldsize = newsize;
    }
    return 0;
}