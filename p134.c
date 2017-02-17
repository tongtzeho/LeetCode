int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int tank = 0;
    int mingas = 2147483647;
    int result = 0;
    int i;
    for (i = 0; i < gasSize; i++)
    {
        tank += gas[i]-cost[i];
        if (tank < mingas)
        {
            mingas = tank;
            result = i;
        }
    }
    if (tank >= 0)
    {
        result++;
        if (result < gasSize) return result;
        return 0;
    }
    return -1;
}
