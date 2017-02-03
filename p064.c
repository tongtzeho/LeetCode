inline int min(const int x, const int y)
{
    if (x < y) return x;
    return y;
}

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int *mem = (int*)malloc(sizeof(int)*gridColSize);
    int i, j;
    mem[0] = grid[0][0];
    for (j = 1; j < gridColSize; j++)
    {
        mem[j] = grid[0][j]+mem[j-1];
    }
    for (i = 1; i < gridRowSize; i++)
    {
        mem[0] += grid[i][0];
        for (j = 1; j < gridColSize; j++)
        {
            mem[j] = grid[i][j]+min(mem[j-1], mem[j]);
        }
    }
    return mem[gridColSize-1];    
}