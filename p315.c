/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    if (!numsSize) return NULL;
    int *temp = (int*)malloc(sizeof(int)*numsSize);
    int *val = (int*)malloc(sizeof(int)*numsSize);
    int *index = (int*)malloc(sizeof(int)*numsSize);
    int *result = (int*)malloc(sizeof(int)*numsSize);
    int i, j, k;
    for (i = 0; i < numsSize; i++)
    {
        index[i] = i;
        result[i] = 0;
    }
    for (i = 1; i < numsSize; i <<= 1)
    {
        j = 0;
        while (true)
        {
            k = j+i;
            if (k >= numsSize) break;
            int j0 = j, k0 = k, j1 = k, k1 = k+i, add = 0;
            if (k1 > numsSize)
            {
                k1 = numsSize;
            }
            while (j < j1 || k < k1)
            {
                if (j < j1 && (k == k1 || nums[j] <= nums[k]))
                {
                    temp[j+k-j0-k0] = index[j];
                    val[j+k-j0-k0] = nums[j];
                    result[index[j]] += add;
                    j++;
                }
                else
                {
                    temp[j+k-j0-k0] = index[k];
                    val[j+k-j0-k0] = nums[k];
                    k++;
                    add++;
                }
            }
            for (j = j0; j < k1; j++)
            {
                index[j] = temp[j-j0];
                nums[j] = val[j-j0];
            }
            j = k1;
        }
    }
    return result;
}