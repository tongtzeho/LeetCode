bool isSquare(int n) {
    return ((int)(sqrt(n)))*((int)(sqrt(n))) == n;
}

int numSquares(int n) {
    if (n <= 3) return n;
    if (isSquare(n)) return 1;
    while (n % 4 == 0)
    {
        n /= 4;
    }
    if (n % 8 == 7) return 4;
    int i, j;
    for (i = 1; i*i < n; i++)
        if (isSquare(n-i*i)) return 2;
    return 3;
}