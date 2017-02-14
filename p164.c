struct MyInterval {
    int min;
    int max;
};

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) return 0;
    struct MyInterval *interval = (struct MyInterval*)malloc(sizeof(struct MyInterval)*(numsSize+1));
    long long min = nums[0], max = nums[0];
    int i, j;
    for (i = 0; i < numsSize; i++)
    {
        interval[i].min = interval[i].max = -1;
        if (nums[i] < min) min = nums[i];
        else if (nums[i] > max) max = nums[i];
    }
    if (min == max) return 0;
    interval[numsSize].min = interval[numsSize].max = -1;
    long long max_min = max-min+1;
    for (i = 0; i < numsSize; i++)
    {
        j = (nums[i]-min)*(numsSize+1)/max_min;
        if (interval[j].min == -1)
        {
            interval[j].min = interval[j].max = nums[i];
        }
        else
        {
            if (nums[i] < interval[j].min) interval[j].min = nums[i];
            else if (nums[i] > interval[j].max) interval[j].max = nums[i];
        }
    }
    max = interval[0].max;
    int tmp, result = 0;
    for (i = 1; i <= numsSize; i++)
    {
        if (interval[i].min != -1)
        {
            tmp = interval[i].min-max;
            if (tmp > result)
            {
                result = tmp;
            }
            max = interval[i].max;
        }
    }
    return result;
}
