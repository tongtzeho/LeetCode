int rangeBitwiseAnd(int m, int n) {
    int result = 0;
    int i;
    for (i = 30; i >= 0; i--)
    {
        int temp = result | (1 << i);
        if (n < temp)
        {
            continue;
        }
        else if (m >= temp)
        {
            result = temp;
        }
        else
        {
            return result;
        }
    }
    return result;
}
