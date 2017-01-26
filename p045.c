int jump(int* nums, int numsSize) {
    if (numsSize <= 2) return numsSize-1;
    int **mem = (int**)malloc(sizeof(int*)*numsSize);
    int *memsize = (int*)malloc(sizeof(int)*numsSize);
    int i, j;
    for (i = 0; i < numsSize; i++)
    {
        memsize[i] = 0;
    }
    for (i = 0; i < numsSize-1; i++)
    {
        nums[i] += i;
        if (nums[i] >= numsSize) nums[i] = numsSize-1;
        memsize[nums[i]]++;
    }
    for (i = 0; i < numsSize; i++)
    {
        if (memsize[i])
        {
            mem[i] = (int*)malloc(sizeof(int*)*memsize[i]);
            memsize[i] = 0;
        }
    }
    for (i = 0; i < numsSize-1; i++)
    {
        mem[nums[i]][memsize[nums[i]]++] = i;
    }
    int searchmin = numsSize-1;
    int lastsearchmin = numsSize;
    int result = 0;
    while (searchmin > 0)
    {
        int tmp = searchmin;
        for (i = searchmin; i < lastsearchmin; i++)
        {
            for (j = 0; j < memsize[i]; j++)
            {
                if (mem[i][j] < tmp)
                {
                    tmp = mem[i][j];
                    if (tmp == 0) break;
                }
            }
            if (tmp == 0) break;
        }
        result++;
        lastsearchmin = searchmin;
        searchmin = tmp;
    }
    return result;
}