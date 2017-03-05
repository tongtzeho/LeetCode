int majorityElement(int* nums, int numsSize) {
    int oldsize = numsSize;
    int newsize = 0;
    int i;
    while (oldsize > 1)
    {
        newsize = 0;
        for (i = 0; i < oldsize; i += 2)
        {
            if (i == oldsize-1 || nums[i] == nums[i+1])
            {
                nums[newsize++] = nums[i];
            }
        }
        oldsize = newsize;
    }
    return nums[0];
}