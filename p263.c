bool isUgly(int num) {
    if (num <= 0) return false;
    while (num % 15 == 0)
    {
        num /= 15;
    }
    while (num % 3 == 0)
    {
        num /= 3;
    }
    while (num % 5 == 0)
    {
        num /= 5;
    }
    return (num&(num-1)) == 0;
}
