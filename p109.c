/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
struct TreeNode *f(const int *arr, const int begin, const int end)
{
    struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int mid = (begin+end)>>1;
    node->val = arr[mid];
    if (begin == mid) node->left = NULL;
    else node->left = f(arr, begin, mid);
    if (end == mid+1) node->right = NULL;
    else node->right = f(arr, mid+1, end);
    return node;
}
 
struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (!head) return NULL;
    int size = 0;
    struct ListNode *node = head;
    while (node != NULL)
    {
        size++;
        node = node->next;
    }
    int *arr = (int*)malloc(sizeof(int)*size);
    node = head;
    size = 0;
    while (node != NULL)
    {
        arr[size++] = node->val;
        node = node->next;
    }
    return f(arr, 0, size);
}