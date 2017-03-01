int minPatches(int* nums, int numsSize, int n) {
    long long upper = 0;
    long long lln = n;
    int i = 0;
    int result = 0;
    int patch;
    while (upper < lln)
    {
        if (i == numsSize || (long long)nums[i] > upper+1)
        {
            result++;
            upper = (upper<<1)+1;
        }
        else
        {
            upper += (long long)nums[i++];
        }
    }
    return result;
}
