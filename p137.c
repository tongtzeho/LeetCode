int singleNumber(int* nums, int numsSize) {
    unsigned char arr[21] = {0};
    int i, j;
    for (i = 0; i < numsSize; i++)
    {
        unsigned u = nums[i];
        for (j = 0; u > 0; j++)
        {
            arr[j] += u%3;
            if (arr[j] >= 3) arr[j] -= 3;
            u /= 3;
        }
    }
    unsigned uresult = 0;
    i = 1;
    for (j = 0; j < 21; j++)
    {
        uresult += ((unsigned)arr[j])*i;
        i += i+i;
    }
    return uresult;
}
