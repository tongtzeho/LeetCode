void rotate(int* nums, int numsSize, int k) {
    if (!numsSize) return;
    int pos = 0;
    k %= numsSize;
    while (pos+k < numsSize && k > 0)
    {
        int i;
        for (i = 0; i < k; i++)
        {
            if (pos+i == numsSize-k)
            {
                k -= i;
                break;
            }
            nums[pos+i] ^= nums[numsSize-k+i];
            nums[numsSize-k+i] ^= nums[pos+i];
            nums[pos+i] ^= nums[numsSize-k+i];
        }
        pos += i;
    }
}
