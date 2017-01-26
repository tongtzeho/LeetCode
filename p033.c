int search(int* nums, int numsSize, int target) {
    int l = 0;
    int r = numsSize;
    while (r - l > 1)
    {
        int m = (l+r+1) >> 1;
        if (nums[m] > nums[numsSize-1]) l = m;
        else r = m;
    }
    int pivot = l;
    l = 0;
    r = pivot;
    while (r > l)
    {
        int m = (l+r) >> 1;
        if (nums[m] > target) r = m-1;
        else if (nums[m] < target) l = m+1;
        else return m;
    }
    if (nums[l] == target) return l;
    l = pivot+1;
    r = numsSize-1;
    while (r > l)
    {
        int m = (l+r) >> 1;
        if (nums[m] > target) r = m-1;
        else if (nums[m] < target) l = m+1;
        else return m;
    }
    if (l < numsSize && nums[l] == target) return l;
    return -1;
}