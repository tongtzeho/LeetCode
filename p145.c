/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    (*returnSize) = 0;
    if (!root)
    {
        
        return NULL;
    }
    struct ListNode head;
    struct ListNode *node = &head;
    struct TreeNode *tmp;
    while (root != NULL)
    {
        if (root->right != NULL)
        {
            tmp = root->right;
            while (tmp->left != NULL && tmp->left != root)
            {
                tmp = tmp->left;
            }
            if (tmp->left == root)
            {
                tmp->left = NULL;
                root = root->left;
            }
            else
            {
                tmp->left = root;
                node->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                node = node->next;
                node->val = root->val;
                (*returnSize)++;
                root = root->right;
            }
        }
        else
        {
            node->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            node = node->next;
            node->val = root->val;
            (*returnSize)++;
            root = root->left;
        }
    }
    int *result = (int*)malloc(sizeof(int)*(*returnSize));
    int i;
    node = head.next;
    for (i = (*returnSize)-1; i >= 0; i--)
    {
        result[i] = node->val;
        node = node->next;
    }
    return result;
}