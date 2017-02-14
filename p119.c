/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex+1;
    int *result = (int*)malloc(sizeof(int)*(*returnSize));
    int i;
    result[0] = result[rowIndex] = 1;
    for (i = 1; i <= rowIndex>>1; i++)
    {
        result[i] = result[rowIndex-i] = ((long long)result[i-1])*(rowIndex-i+1)/i;
    }
    return result;
}
