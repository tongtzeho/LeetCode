int numIslands(char** grid, int gridRowSize, int gridColSize) {
    int result = 0;
    if (gridRowSize == 0) return 0;
    int *stackrid = (int*)malloc(sizeof(int)*(gridRowSize*gridColSize));
    int *stackcid = (int*)malloc(sizeof(int)*(gridRowSize*gridColSize));
    int stacksize = 0;
    int i, j;
    for (i = 0; i < gridRowSize; i++)
    {
        for (j = 0; j < gridColSize; j++)
        {
            if (grid[i][j] == '1')
            {
                result++;
                stackrid[stacksize] = i;
                stackcid[stacksize++] = j;
                while (stacksize > 0)
                {
                    int rid = stackrid[--stacksize];
                    int cid = stackcid[stacksize];
                    grid[rid][cid] = '2';
                    if (rid > 0 && grid[rid-1][cid] == '1')
                    {
                        stackrid[stacksize] = rid-1;
                        stackcid[stacksize++] = cid;
                    }
                    if (rid < gridRowSize-1 && grid[rid+1][cid] == '1')
                    {
                        stackrid[stacksize] = rid+1;
                        stackcid[stacksize++] = cid;
                    }
                    if (cid > 0 && grid[rid][cid-1] == '1')
                    {
                        stackrid[stacksize] = rid;
                        stackcid[stacksize++] = cid-1;
                    }
                    if (cid < gridColSize-1 && grid[rid][cid+1] == '1')
                    {
                        stackrid[stacksize] = rid;
                        stackcid[stacksize++] = cid+1;
                    }
                }
            }
        }
    }
    return result;
}
