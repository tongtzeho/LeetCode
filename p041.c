int firstMissingPositive(int* nums, int numsSize) {
    int i, tmp;
    for (i = 0; i < numsSize; i++)
    {
        while (nums[i] > 0 && nums[i] <= numsSize && nums[nums[i]-1] != nums[i])
        {
            tmp = nums[nums[i]-1];
            nums[nums[i]-1] = nums[i];
            nums[i] = tmp;
        }
    }
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] != i+1) return i+1;
    }
    return numsSize+1;
}