/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    *returnSize = (1<<numsSize);
    int i, j, k;
    int **result = (int**)malloc(sizeof(int*)*(*returnSize));
    (*columnSizes) = (int*)malloc(sizeof(int)*(*returnSize));
    for (i = 0; i < *returnSize; i++)
    {
        j = i;
        k = 0;
        (*columnSizes)[i] = 0;
        result[i] = (int*)malloc(sizeof(int)*numsSize);
        while (j > 0)
        {
            if (j&1) result[i][(*columnSizes)[i]++] = nums[k];
            j >>= 1;
            k++;
        }
    }
    return result;    
}
