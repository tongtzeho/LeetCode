inline int max(int x, int y) {
    if (x > y) return x;
    return y;
}

int longestPalindromeSubseq(char* s) {
    int len = strlen(s);
    if (len == 0) return 0;
    int *mem0 = (int*)malloc(sizeof(int)*len);
    int *mem1 = (int*)malloc(sizeof(int)*len);
    int *mem2 = (int*)malloc(sizeof(int)*len);
    int *tmp;
    int i, j;
    for (i = 0; i < len; i++)
    {
        mem0[i] = 0;
        mem1[i] = 1;
    }
    for (i = 1; i < len; i++)
    {
        for (j = 0; j < len-i; j++)
        {
            if (s[j] == s[j+i])
            {
                mem2[j] = 2+mem0[j+1];
            }
            else
            {
                mem2[j] = max(mem1[j], mem1[j+1]);
            }
        }
        tmp = mem0;
        mem0 = mem1;
        mem1 = mem2;
        mem2 = tmp;
    }
    return mem1[0];
}
