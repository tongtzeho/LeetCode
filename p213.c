inline int max(int x, int y) {
    if (x > y) return x;
    return y;
}

int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    if (numsSize == 2) return max(nums[0], nums[1]);
    int i;
    int *arr = (int*)malloc(sizeof(int)*numsSize);
    arr[0] = 0;
    arr[1] = nums[1];
    arr[2] = nums[2];
    for (i = 3; i < numsSize; i++)
    {
        arr[i] = nums[i]+max(arr[i-2], arr[i-3]);
    }
    int result1 = max(arr[i-1], arr[i-2]);
    if (numsSize == 3) return max(result1, nums[0]);
    nums[2] += nums[0];
    for (i = 3; i < numsSize-1; i++)
    {
        nums[i] += max(nums[i-2], nums[i-3]);
    }
    int result2 = max(nums[i-1], nums[i-2]);
    return max(result1, result2);
} 
