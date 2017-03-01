int **mem;
int result;

inline int max(int x, int y) {
    if (x > y) return x;
    return y;
}

int f(int **m, int x, int y, int r, int c) {
    if (mem[x][y] != -1) return mem[x][y];
    mem[x][y] = 1;
    if (x > 0 && m[x-1][y] > m[x][y]) mem[x][y] = max(mem[x][y], f(m, x-1, y, r, c)+1);
    if (y > 0 && m[x][y-1] > m[x][y]) mem[x][y] = max(mem[x][y], f(m, x, y-1, r, c)+1);
    if (x < r-1 && m[x+1][y] > m[x][y]) mem[x][y] = max(mem[x][y], f(m, x+1, y, r, c)+1);
    if (y < c-1 && m[x][y+1] > m[x][y]) mem[x][y] = max(mem[x][y], f(m, x, y+1, r, c)+1);
    return mem[x][y];
}

int longestIncreasingPath(int** matrix, int matrixRowSize, int matrixColSize) {
    if (matrixRowSize == 0 || matrixColSize == 0) return 0;
    result = 1;
    int i, j;
    mem = (int**)malloc(sizeof(int*)*matrixRowSize);
    for (i = 0; i < matrixRowSize; i++)
    {
        mem[i] = (int*)malloc(sizeof(int)*matrixColSize);
        for (j = 0; j < matrixColSize; j++)
        {
            mem[i][j] = -1;
        }
    }
    for (i = 0; i < matrixRowSize; i++)
        for (j = 0; j < matrixColSize; j++)
        {
            result = max(f(matrix, i, j, matrixRowSize, matrixColSize), result);
        }
    return result;
}
