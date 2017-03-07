inline int max(int x, int y) {
    if (x > y) return x;
    return y;
}

int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    if (numsSize == 2) return max(nums[0], nums[1]);
    int i;
    nums[2] += nums[0];
    for (i = 3; i < numsSize; i++)
    {
        nums[i] += max(nums[i-2], nums[i-3]);
    }
    return max(nums[i-1], nums[i-2]);
} 
