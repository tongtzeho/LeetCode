inline int minimum(int x, int y)
{
    if (x < y) return x;
    return y;
}

int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize) {
    int result = 0;
    int i, j;
    for (i = 0; i < matrixRowSize; i++)
        for (j = 0; j < matrixColSize; j++)
        {
            if (i > 0 && j > 0 && matrix[i][j] == '1')
            {
                matrix[i][j] = minimum(matrix[i-1][j-1], minimum(matrix[i-1][j], matrix[i][j-1]))+1;
            }
            else
            {
                matrix[i][j] -= '0';
            }
            if (matrix[i][j] > result) result = matrix[i][j];
        }
    return result*result;
}
