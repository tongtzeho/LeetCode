int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    if (obstacleGrid[0][0] || obstacleGrid[obstacleGridRowSize-1][obstacleGridColSize-1]) return 0;
    int *mem = (int*)malloc(sizeof(int)*obstacleGridColSize);
    int i, j;
    mem[0] = 1;
    for (j = 1; j < obstacleGridColSize; j++)
    {
        if (obstacleGrid[0][j]) mem[j] = 0;
        else mem[j] = mem[j-1];
    }
    for (i = 1; i < obstacleGridRowSize; i++)
    {
        if (obstacleGrid[i][0]) mem[0] = 0;
        for (j = 1; j < obstacleGridColSize; j++)
        {
            if (obstacleGrid[i][j]) mem[j] = 0;
            else mem[j] += mem[j-1];
        }
    }
    return mem[obstacleGridColSize-1];
}