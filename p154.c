int findMin(int* nums, int numsSize) {
    if (numsSize == 1 || nums[0] < nums[numsSize-1]) return nums[0];
    int i;
    for (i = 1; i < numsSize; i++)
    {
        if (nums[i] < nums[0]) return nums[i];
    }
    return nums[0];
}
