/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) return 0;
    *returnSize = 1;
    int i, j, k;
    for (i = 1; i < numsSize; i++)
    {
        *returnSize *= (i+1);
    }
    int *index = (int*)malloc(sizeof(int)*numsSize);
    for (i = 0; i < numsSize; i++)
        index[i] = i;
    int **result = (int**)malloc(sizeof(int*)*(*returnSize));
    for (i = 0; i < *returnSize; i++)
    {
        result[i] = (int*)malloc(sizeof(int)*numsSize);
        for (j = 0; j < numsSize; j++)
        {
            result[i][j] = nums[index[j]];
        }
        for (j = numsSize-1; j > 0; j--)
        {
            if (index[j-1] < index[j])
            {
                for (k = j+1; k < numsSize; k++)
                {
                    if (index[k] < index[j-1])
                    {
                        break;
                    }
                }
                k--;
                index[j-1] ^= index[k];
                index[k] ^= index[j-1];
                index[j-1] ^= index[k];
                for (k = j; k < (j+numsSize)>>1; k++)
                {
                    index[k] ^= index[j+numsSize-1-k];
                    index[j+numsSize-1-k] ^= index[k];
                    index[k] ^= index[j+numsSize-1-k];
                }
                break;
            }
        }
    }
    return result;
}