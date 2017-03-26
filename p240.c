bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    if (matrixRowSize <= matrixColSize)
    {
        int right = matrixColSize;
        int i;
        for (i = 0; i < matrixRowSize; i++)
        {
            int left = 0;
            while (right > left)
            {
                int mid = (left+right)>>1;
                if (matrix[i][mid] == target)
                {
                    return true;
                }
                else if (matrix[i][mid] > target)
                {
                    right = mid;
                }
                else
                {
                    left = mid+1;
                }
            }
            if (right == 0)
            {
                return false;
            }
        }
        return false;
    }
    else
    {
        int right = matrixRowSize;
        int i;
        for (i = 0; i < matrixColSize; i++)
        {
            int left = 0;
            while (right > left)
            {
                int mid = (left+right)>>1;
                if (matrix[mid][i] == target)
                {
                    return true;
                }
                else if (matrix[mid][i] > target)
                {
                    right = mid;
                }
                else
                {
                    left = mid+1;
                }
            }
            if (right == 0)
            {
                return false;
            }
        }
        return false;
    }
}