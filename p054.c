/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    unsigned size = matrixRowSize*matrixColSize;
    if (!size) return NULL;
    int *result = (int*)malloc(sizeof(int)*size);
    unsigned up = 1, right = matrixColSize-1, down = matrixRowSize-1, left = 0;
    unsigned dir = 0, i = 0, j = 0;
    size = 0;
    while (true)
    {
        result[size++] = matrix[i][j];
        if (dir == 0)
        {
            if (j < right)
            {
                j++;
            }
            else if (i < down)
            {
                i++;
                right--;
                dir = 1;
            }
            else
            {
                break;
            }
        }
        else if (dir == 1)
        {
            if (i < down)
            {
                i++;
            }
            else if (j > left)
            {
                j--;
                down--;
                dir = 2;
            }
            else
            {
                break;
            }
        }
        else if (dir == 2)
        {
            if (j > left)
            {
                j--;
            }
            else if (i > up)
            {
                i--;
                left++;
                dir = 3;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (i > up)
            {
                i--;
            }
            else if (j < right)
            {
                j++;
                up++;
                dir = 0;
            }
            else
            {
                break;
            }
        }
    }
    return result;
}