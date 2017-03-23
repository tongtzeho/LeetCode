/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *result = (int*)malloc(sizeof(int)*numsSize);
    int i;
    result[0] = 1;
    for (i = 1; i < numsSize; i++)
    {
        result[i] = result[i-1]*nums[i-1];
    }
    int rightproduct = 1;
    for (i = numsSize-1; i >= 0; i--)
    {
        result[i] *= rightproduct;
        rightproduct *= nums[i];
    }
    return result;
}
