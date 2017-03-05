char* convertToTitle(int n) {
    char *result = (char*)malloc(sizeof(char)*10);
    int len = 1;
    long long cnt = 26;
    long long lln = n-1;
    int i = 0;
    while (lln >= cnt)
    {
        lln -= cnt;
        cnt *= 26;
        len++;
    }
    result[len] = '\0';
    for (i = 0; i < len; i++)
    {
        cnt /= 26;
        result[i] = (lln/cnt)%26+'A';
    }
    return result;
}