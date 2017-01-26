void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    int halfup = (matrixRowSize+1)>>1;
    int halfdown = matrixRowSize>>1;
    matrixRowSize--;
    int i, j, tmp;
    for (i = 0; i < halfup; i++)
        for (j = 0; j < halfdown; j++)
        {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[matrixRowSize-j][i];
            matrix[matrixRowSize-j][i] = matrix[matrixRowSize-i][matrixRowSize-j];
            matrix[matrixRowSize-i][matrixRowSize-j] = matrix[j][matrixRowSize-i];
            matrix[j][matrixRowSize-i] = tmp;
        }
}