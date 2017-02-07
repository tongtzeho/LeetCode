int maxProfit(int* prices, int pricesSize) {
    if (!pricesSize) return 0;
    int i;
    int min = prices[0];
    int max = prices[0];
    bool up = false;
    int result = 0;
    int tmp;
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
            else
            {
                if (prices[i] > max)
                {
                    max = prices[i];
                }
            }
        }
        tmp = prices[i]-min;
        if (tmp > result)
        {
            result = tmp;
        }
    }
    return result;
}