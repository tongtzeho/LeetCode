int numTrees(int n) {
    if (!n) return 0;
    int *a = (int*)malloc(sizeof(int)*(n+1));
    a[0] = a[1] = 1;
    int i, j;
    for (i = 2; i <= n; i++)
    {
        a[i] = 0;
        if (i&1)
        {
            
            for (j = 0; j < (i>>1); j++)
            {
                a[i] += a[j]*a[i-1-j];
            }
            a[i] = (a[i]<<1)+a[i>>1]*a[i>>1];
        }
        else
        {
            for (j = 0; j < (i>>1); j++)
            {
                a[i] += a[j]*a[i-1-j];
            }
            a[i] <<= 1;
        }
    }
    return a[n];
}