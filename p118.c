/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
    if (!numRows) return NULL;
    int **result = (int**)malloc(sizeof(int*)*numRows);
    (*columnSizes) = (int*)malloc(sizeof(int)*numRows);
    int i, j;
    for (i = 0; i < numRows; i++)
    {
        (*columnSizes)[i] = i+1;
        result[i] = (int*)malloc(sizeof(int)*(i+1));
        result[i][0] = result[i][i] = 1;
        for (j = 1; j < i; j++)
        {
            result[i][j] = result[i-1][j-1]+result[i-1][j];
        }
    }
    return result;
}
