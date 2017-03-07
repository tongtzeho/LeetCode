int minSubArrayLen(int s, int* nums, int numsSize) {
    int i = 0;
    int j = 0;
    int result = numsSize+2;
    int sum = 0;
    while (i < numsSize)
    {
        if (i == j || sum < s)
        {
            if (j == numsSize) break;
            sum += nums[j++];
        }
        else
        {
            if (j-i < result)
            {
                result = j-i;
            }
            sum -= nums[i++];
        }
    }
    if (result > numsSize) return 0;
    return result;
}
