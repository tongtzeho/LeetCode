bool canJump(int* nums, int numsSize) {
    int maxpos = 0;
    int i;
    for (i = 0; i <= maxpos; i++)
    {
        if (i+nums[i] > maxpos)
        {
            maxpos = i+nums[i];
            if (maxpos >= numsSize-1) return true;
        }
    }
    return maxpos >= numsSize-1;
}