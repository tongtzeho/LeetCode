void sortColors(int* nums, int numsSize) {
    unsigned cnt[3] = {0};
    unsigned i, j, k = 0;
    for (i = 0; i < numsSize; i++)
    {
        cnt[nums[i]]++;
    }
    for (i = 0; i < 3; i++)
        for (j = 0; j < cnt[i]; j++)
            nums[k++] = i;
}