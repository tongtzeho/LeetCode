int hIndex(int* citations, int citationsSize) {
    if (!citationsSize) return 0;
    int *cnt = (int*)malloc(sizeof(int)*(citationsSize+1));
    int i;
    for (i = 0; i <= citationsSize; i++)
    {
        cnt[i] = 0;
    }
    for (i = 0; i < citationsSize; i++)
    {
        if (citations[i] >= citationsSize)
        {
            cnt[citationsSize]++;
        }
        else
        {
            cnt[citations[i]]++;
        }
    }
    int sum = 0;
    for (i = citationsSize; i >= 0; i--)
    {
        sum += cnt[i];
        if (sum >= i) return i;
    }
    return 0;
}