int countPrimes(int n) {
    if (n < 3) return 0;
    bool *isprime = (bool*)malloc(sizeof(bool)*n);
    long long i;
    long long j;
    for (j = 0; j < n; j++)
    {
        isprime[j] = true;
    }
    for (i = 3; i*i <= n; i += 2)
    {
        if (!isprime[i]) continue;
        for (j = 2; i*j <= n; j++)
        {
            isprime[i*j] = false;
        }
    }
    int result = 1;
    for (i = 3; i < n; i += 2)
    {
        result += isprime[i];
    }
    return result;
}
