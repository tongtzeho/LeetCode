char* getPermutation(int n, int k) {
    char* result = (char*)malloc(sizeof(char)*(n+1));
    int next[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, -1};
    int prev[10] = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8};
    int head = 0;
    const int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    k--;
    int i, j, l;
    for (i = 0; i < n; i++)
    {
        j = k%fact[n-i]/fact[n-i-1];
        l = head;
        while (j > 0)
        {
            l = next[l];
            j--;
        }
        if (next[l] != -1)
        {
            prev[next[l]] = prev[l];
        }
        if (prev[l] != -1)
        {
            next[prev[l]] = next[l];
        }
        else
        {
            head = next[l];
        }
        result[i] = l+'1';
    }
    result[n] = '\0';
    return result;
}