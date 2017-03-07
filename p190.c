uint32_t reverseBits(uint32_t n) {
    int i = 0, j = 31;
    uint32_t result = 0;
    while (j > i)
    {
        result += (((n>>i)&1)<<j)+(((n>>j)&1)<<i);
        j--;
        i++;
    }
    return result;
}
