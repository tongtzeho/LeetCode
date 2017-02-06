/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    *returnSize = 1<<n;
    int *result = (int*)malloc(sizeof(int)*(*returnSize));
    int i;
    result[0] = 0;
    for (i = 1; i < *returnSize; i++)
    {
        result[i] = result[i-1]^(i&(-i));
    }
    return result;
}