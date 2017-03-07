bool mem[730] = {0};

bool isHappy(int n) {
    if (n == 1) return true;
    int x = 0;
    while (n > 0)
    {
        x += (n%10)*(n%10);
        n /= 10;
    }
    if (x == 1) return true;
    for (int i = 0; i < 730; i++)
    {
        mem[i] = false;
    }
    while (!mem[x])
    {
        mem[x] = true;
        n = x;
        x = 0;
        while (n > 0)
        {
            x += (n%10)*(n%10);
            n /= 10;
        }
        if (x == 1) return true;
    }
    return false;
}
