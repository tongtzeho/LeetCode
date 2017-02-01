int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
    int i, j;
    int result = 0;
    for (i = 0; i < gridRowSize; i++)
    {
        result += grid[i][0]+grid[i][gridColSize-1];
    }
    for (j = 0; j < gridColSize; j++)
    {
        result += grid[0][j]+grid[gridRowSize-1][j];
    }
    int tmp = 0, tmp2;
    for (j = 0; j < gridColSize; j++)
    {
        tmp = grid[0][j];
        for (i = 1; i < gridRowSize; i++)
        {
            tmp2 = grid[i][j];
            result += tmp^tmp2;
            tmp = tmp2;
        }
    }
    for (i = 0; i < gridRowSize; i++)
    {
        tmp = grid[i][0];
        for (j = 1; j < gridColSize; j++)
        {
            tmp2 = grid[i][j];
            result += tmp^tmp2;
            tmp = tmp2;
        }
    }
    return result;
}