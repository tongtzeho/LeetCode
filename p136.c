int singleNumber(int* nums, int numsSize) {
    int result = 0;
    int i;
    for (i = 0; i < numsSize; i++)
    {
        result ^= nums[i];
    }
    return result;
}
