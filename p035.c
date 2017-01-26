int searchInsert(int* nums, int numsSize, int target) {
    if (numsSize == 0) return 0;
    int l = 0;
    int r = numsSize;
    while (r-l > 1)
    {
        int m = (l+r)>>1;
        if (nums[m] == target) return m;
        else if (nums[m] < target) l = m+1;
        else r = m;
    }
    if (l < numsSize && nums[l] < target) return l+1;
    return l;
}