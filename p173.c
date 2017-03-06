/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct BSTIterator {
    struct TreeNode **stack;
    int stacksize;
};

struct BSTIterator *bstIteratorCreate(struct TreeNode *root) {
    struct BSTIterator *iter = (struct BSTIterator*)malloc(sizeof(struct BSTIterator));
    iter->stacksize = 0;
    iter->stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*1000);
    struct TreeNode *node = root;
    while (node != NULL)
    {
        iter->stack[iter->stacksize++] = node;
        node = node->left;
    }
    return iter;
}

/** @return whether we have a next smallest number */
bool bstIteratorHasNext(struct BSTIterator *iter) {
    return iter->stacksize != 0;
}

/** @return the next smallest number */
int bstIteratorNext(struct BSTIterator *iter) {
    int ret = iter->stack[iter->stacksize-1]->val;
    struct TreeNode *node = iter->stack[iter->stacksize-1]->right;
    if (node != NULL)
    {
        iter->stack[iter->stacksize++] = node;
        node = node->left;
        while (node != NULL)
        {
            iter->stack[iter->stacksize++] = node;
            node = node->left;
        }
    }
    else
    {
        while (true)
        {
            node = iter->stack[--(iter->stacksize)];
            if (iter->stacksize > 0)
            {
                if (iter->stack[iter->stacksize-1]->left == node)
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    return ret;
}

/** Deallocates memory previously allocated for the iterator */
void bstIteratorFree(struct BSTIterator *iter) {
    
}

/**
 * Your BSTIterator will be called like this:
 * struct BSTIterator *i = bstIteratorCreate(root);
 * while (bstIteratorHasNext(i)) printf("%d\n", bstIteratorNext(i));
 * bstIteratorFree(i);
 */
