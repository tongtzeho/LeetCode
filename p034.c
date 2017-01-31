/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *result = (int*)malloc(sizeof(int)*2);
    *returnSize = 2;
    unsigned l = 0;
    unsigned r = numsSize;
    if (!r)
    {
        result[0] = result[1] = -1;
        return result;
    }
    unsigned rr = r;
    unsigned m;
    while (r-l > 1)
    {
        m = (r+l)>>1;
        if (nums[m] < target)
        {
            l = m;
        }
        else
        {
            r = m;
            if (nums[m] > target) rr = m;
        }
    }
    result[0] = l;
    if (nums[result[0]] < target)
    {
        result[0]++;
        if (result[0] >= numsSize || nums[result[0]] != target)
        {
            result[0] = result[1] = -1;
            return result;
        }
    }
    else if (nums[result[0]] > target)
    {
        result[0] = result[1] = -1;
        return result;
    }
    l = result[0];
    r = rr;
    while (r-l > 1)
    {
        m = (r+l)>>1;
        if (nums[m] > target)
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }
    result[1] = l;
    return result;
}