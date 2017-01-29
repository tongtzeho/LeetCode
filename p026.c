int removeDuplicates(int* nums, int numsSize) {
    if (!numsSize) return 0;
    int result = 1;
    int flag = nums[0];
    int i;
    for (i = 1; i < numsSize; i++)
    {
        if (nums[i] != flag)
        {
            nums[result++] = flag = nums[i];
        }
    }
    return result;
}