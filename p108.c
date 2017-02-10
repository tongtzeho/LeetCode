/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
struct TreeNode* f(int *nums, int begin, int end) {
    struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int mid = (begin+end)>>1;
    node->val = nums[mid];
    if (begin == mid) node->left = NULL;
    else node->left = f(nums, begin, mid);
    if (mid == end-1) node->right = NULL;
    else node->right = f(nums, mid+1, end);
    return node;
}
 
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (!numsSize) return NULL;
    return f(nums, 0, numsSize);
}