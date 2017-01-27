double myPow(double x, int n) {
    double result = 1;
    long long nn = n;
    if (nn < 0)
    {
        nn = -nn;
        x = 1/x;
    }
    else if (nn == 0)
    {
        return 1;
    }
    double mem = x;
    long long n2 = 1;
    for (n2 = 1; n2 <= nn; n2 <<= 1)
    {
        if (nn & n2) result *= mem;
        mem *= mem;
    }
    return result;
}