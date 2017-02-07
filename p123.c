int maxProfit(int* prices, int pricesSize) {
    if (!pricesSize) return 0;
    int *mem = (int*)malloc(sizeof(int)*pricesSize);
    int max = prices[pricesSize-1];
    int min = prices[pricesSize-1];
    bool up = false;
    int i;
    int result = 0;
    int tmp;
    mem[pricesSize-1] = 0;
    for (i = pricesSize-2; i >= 0; i--)
    {
        if (prices[i] > max)
        {
            max = prices[i];
            up = false;
        }
        else
        {
            if (!up)
            {
                min = prices[i];
                up = true;
            }
            else if (prices[i] < min)
            {
                min = prices[i];
            }
        }
        tmp = max-prices[i];
        if (tmp > result) result = tmp;
        mem[i] = result;
    }
    max = min = prices[0];
    up = false;
    result = 0;
    for (i = 1; i < pricesSize; i++)
    {
        if (prices[i] < min)
        {
            min = prices[i];
            up = false;
        }
        else
        {
            if (!up)
            {
                max = prices[i];
                up = true;
            }
            else if (prices[i] > max)
            {
                max = prices[i];
            }
        }
        tmp = prices[i]-min+mem[i];
        if (tmp > result) result = tmp; 
    }
    return result;
}