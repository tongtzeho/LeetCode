int removeElement(int* nums, int numsSize, int val) {
    int result = 0;
    int i;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
        {
            nums[result++] = nums[i];
        }
    }
    return result;
}