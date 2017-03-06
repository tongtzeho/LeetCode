int trailingZeroes(int n) {
    long long result = 0;
    long long temp = 0;
    long long i;
    for (i = 5; ; i *= 5)
    {
        temp = ((long long)n)/i;
        if (temp == 0) break;
        result += temp;
    }
    return result;
}
