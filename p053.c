int maxSubArray(int* nums, int numsSize) {
    int result = nums[0];
    int minval = 0;
    int maxval = nums[0];
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        if (sum > maxval) maxval = sum;
        {
            if (maxval-minval > result) result = maxval-minval;
        }
        if (sum < minval)
        {
            minval = sum;
            maxval = -2147483648;
        }
    }
    return result;
}