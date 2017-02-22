int change(int amount, int* coins, int coinsSize) {
    if (!amount) return 1;
    if (!coinsSize) return 0;
    int *mem = (int*)malloc(sizeof(int)*(amount+1));
    int i, j;
    for (i = 0; i <= amount; i++)
    {
        mem[i] = (i % coins[0] == 0);
    }
    for (i = 1; i < coinsSize; i++)
    {
        for (j = 0; j <= amount; j++)
        {
            if (j >= coins[i])
            {
                mem[j] += mem[j-coins[i]];
            }
        }
    }
    return mem[amount];
}
