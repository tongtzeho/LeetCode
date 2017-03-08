int cmp(const void *a, const void *b)
{
    return (*(int*)a)-(*(int*)b); 
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    int i;
    for (i = 1; i < numsSize; i++)
    {
        if (nums[i] == nums[i-1]) return true;
    }
    return false;
}
