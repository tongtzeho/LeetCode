/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    struct TreeLinkNode *oldlst, *newlst, tmp;
    oldlst = root;
    while (oldlst != NULL)
    {
        tmp.next = NULL;
        newlst = &tmp;
        while (oldlst != NULL)
        {
            if (oldlst->left != NULL)
            {
                newlst->next = oldlst->left;
                newlst = newlst->next;
            }
            if (oldlst->right != NULL)
            {
                newlst->next = oldlst->right;
                newlst = newlst->next;
            }
            oldlst = oldlst->next;
        }
        oldlst = tmp.next;
    }
}
