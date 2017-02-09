int minCut(char* s) {
    int len = strlen(s);
    if (!len) return 0;
    int i, j, tmp;
    int **reach = (int**)malloc(sizeof(int*)*len);
    int *reachsize = (int*)malloc(sizeof(int)*len);
    int *mem = (int*)malloc(sizeof(int)*(len+1));
    for (i = 0; i < len-1; i++)
    {
        reach[i] = (int*)malloc(sizeof(int)*(len-i));
        reachsize[i] = 1;
        reach[i][0] = i+1;
        for (j = 1; i-j >= 0 && i+j < len && s[i-j] == s[i+j]; j++)
            reach[i-j][reachsize[i-j]++] = i+j+1;
        for (j = 0; i-j >= 0 && i+j+1 < len && s[i-j] == s[i+j+1]; j++)
            reach[i-j][reachsize[i-j]++] = i+j+2;
    }
    reach[len-1] = (int*)malloc(sizeof(int));
    reachsize[len-1] = 1;
    reach[len-1][0] = len;
    mem[len] = -1;
    for (i = len-1; i >= 0; i--)
    {
        mem[i] = len;
        for (j = 0; j < reachsize[i]; j++)
        {
            tmp = 1+mem[reach[i][j]];
            if (tmp < mem[i]) mem[i] = tmp;
        }
    }
    return mem[0];
}