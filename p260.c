/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
int partition(int *nums, int left, int right) {
    int pivot = rand()%(right-left)+left;
    int temp = nums[pivot];
    nums[pivot] = nums[right-1];
    nums[right-1] = temp;
    pivot = right-1;
    int i;
    for (i = left; i < pivot; i++)
    {
        if (nums[i] >= nums[pivot])
        {
            temp = nums[pivot];
            nums[pivot] = nums[i];
            nums[i] = temp;
            for (pivot--; pivot > i; pivot--)
            {
                if (nums[pivot] < nums[i])
                {
                    break;
                }
            }
            temp = nums[pivot];
            nums[pivot] = nums[i];
            nums[i] = temp;
        }
    }
    return pivot;
}
 
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int i;
    int cntzero = 0;
    int xorresult = 0;
    for (i = 0; i < numsSize; i++)
    {
        xorresult ^= nums[i];
        if (nums[i] == 0)
        {
            cntzero++;
        }
    }
    if (cntzero == 1)
    {
        *returnSize = 2;
        int *result = (int*)malloc(sizeof(int)*2);
        result[0] = 0;
        result[1] = xorresult;
        return result;
    }
    srand(time(0));
    *returnSize = 2;
    int *result = (int*)malloc(sizeof(int)*2);
    int index = 0;
    int left = 0, right = numsSize;
    while (right-left > 2)
    {
        int pivot = partition(nums, left, right);
        int val1 = 0;
        for (i = left; i < pivot; i++)
        {
            val1 ^= nums[i];
        }
        int val2 = xorresult ^ val1;
        if (val1 != 0 && val2 != 0)
        {
            result[0] = val1;
            result[1] = val2;
            return result;
        }
        else
        {
            if (val1 != 0)
            {
                right = pivot;
                xorresult = val1;
            }
            else
            {
                left = pivot;
                xorresult = val2;
            }
        }
    }
    result[0] = nums[left];
    result[1] = nums[left+1];
    return result;
}
