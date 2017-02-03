void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int i, j;
    bool firstCol = false;
    for (i = 0; i < matrixRowSize; i++)
    {
        if (!matrix[i][0])
        {
            firstCol = true;
            break;
        }
    }
    for (i = 0; i < matrixRowSize; i++)
        for (j = 1; j < matrixColSize; j++)
            if (!matrix[i][j])
            {
                matrix[i][0] = matrix[0][j] = 0;
            }
    for (j = 1; j < matrixColSize; j++)
        if (!matrix[0][j])
        {
            for (i = 1; i < matrixRowSize; i++)
            {
                matrix[i][j] = 0;
            }
        }
    for (i = 0; i < matrixRowSize; i++)
        if (!matrix[i][0])
        {
            for (j = 1; j < matrixColSize; j++)
            {
                matrix[i][j] = 0;
            }
        }
    if (firstCol)
    {
        for (i = 0; i < matrixRowSize; i++)
            matrix[i][0] = 0;
    }
}