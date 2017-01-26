int largestRectangleArea(int* heights, int heightsSize) {
    if (heightsSize == 0) return 0;
    if (heightsSize == 1) return heights[0];
    int *stk = (int*)malloc(sizeof(int)*heightsSize);
    int *rightless = (int*)malloc(sizeof(int)*heightsSize);
    int *leftless = (int*)malloc(sizeof(int)*heightsSize);
    int stksize = 0;
    int i;
    for (i = 0; i < heightsSize; i++)
    {
        rightless[i] = heightsSize;
        leftless[i] = -1;
    }
    for (i = 0; i < heightsSize; i++)
    {
        while (stksize && heights[stk[stksize-1]] > heights[i])
        {
            rightless[stk[--stksize]] = i;
        }
        stk[stksize++] = i;
    }
    stksize = 0;
    for (i = heightsSize-1; i >= 0; i--)
    {
        while (stksize && heights[stk[stksize-1]] > heights[i])
        {
            leftless[stk[--stksize]] = i;
        }
        stk[stksize++] = i;
    }
    int result = 0;
    int tmp = 0;
    for (i = 0; i < heightsSize; i++)
    {
        tmp = heights[i]*(rightless[i]-leftless[i]-1);
        if (tmp > result)
        {
            result = tmp;
        }
    }
    return result;
}