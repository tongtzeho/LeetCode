bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    if ((!matrixRowSize) || (!matrixColSize) || (matrix[0][0] > target)) return false;
    int l = 0;
    int r = matrixRowSize;
    while (r-l > 1)
    {
        int m = (l+r)>>1;
        if (matrix[m][0] < target) l = m;
        else if (matrix[m][0] > target) r = m;
        else return true;
    }
    int row = l;
    l = 0;
    r = matrixColSize;
    while (r-l > 1)
    {
        int m = (l+r)>>1;
        if (matrix[row][m] < target) l = m;
        else if (matrix[row][m] > target) r = m;
        else return true;
    }
    return matrix[row][l] == target;
}