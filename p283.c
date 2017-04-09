void moveZeroes(int* nums, int numsSize) {
    int i = 0;
    int j;
    int mem = -1;
    while (i < numsSize)
    {
        if (nums[i] == 0)
        {
            if (i <= mem)
            {
                j = mem;
            }
            else
            {
                j = i+1;
            }
            while (j < numsSize && nums[j] == 0)
            {
                j++;
            }
            mem = j;
            if (j < numsSize)
            {
                nums[i] ^= nums[j];
                nums[j] ^= nums[i];
                nums[i] ^= nums[j];
            }
        }
        i++;
    }
}