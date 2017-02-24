inline int min(int x, int y) {
    if (x < y) return x;
    return y;
}

inline int max(int x, int y) {
    if (x > y) return x;
    return y;
}

int maxProduct(int* nums, int numsSize) {
    long long result = nums[0];
    long long oldmin = nums[0];
    long long oldmax = nums[0];
    int i;
    long long newmin, newmax;
    for (i = 1; i < numsSize; i++)
    {
        if (nums[i] >= 0)
        {
            oldmin = min(oldmin*nums[i], nums[i]);
            oldmax = max(oldmax*nums[i], nums[i]);
        }
        else
        {
            newmin = min(oldmax*nums[i], nums[i]);
            newmax = max(oldmin*nums[i], nums[i]);
            oldmin = newmin;
            oldmax = newmax;
        }
        if (oldmax > result)
        {
            result = oldmax;
        }
    }
    return result;
}