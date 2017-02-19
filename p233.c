int countDigitOne(int n) {
    int result = 0;
    long long multi = 1;
    long long nextmulti;
    while (n >= multi)
    {
        nextmulti = multi*10;
        result += n/nextmulti*multi;
        if (n % nextmulti >= multi)
        {
            if (n % nextmulti >= multi+multi)
            {
                result += multi;
            }
            else
            {
                result += n % nextmulti - multi + 1;
            }
        }
        multi = nextmulti;
    }
    return result;
}