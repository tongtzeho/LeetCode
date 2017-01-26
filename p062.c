int uniquePaths(int m, int n) {
    int min = n-1;
    if (m < n)
    {
        min = m-1;
    }
    int sum = m+n-2;
    int i;
    long long result = 1;
    for (i = 1; i <= min; i++)
        result = result*(sum-min+i)/i;
    return result;
}