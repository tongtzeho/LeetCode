int maxProfit(int* prices, int pricesSize) {
    int result = 0;
    int i;
    for (i = 1; i < pricesSize; i++)
    {
        if (prices[i] > prices[i-1])
        {
            result += prices[i]-prices[i-1];
        }
    }
    return result;
}