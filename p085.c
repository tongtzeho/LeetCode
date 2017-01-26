int maximalRectangle(char** matrix, int matrixRowSize, int matrixColSize) {
    if (matrixRowSize == 0 || matrixColSize == 0) return 0;
    int *left = (int*)malloc(sizeof(int)*matrixRowSize);
    int *up = (int*)malloc(sizeof(int)*matrixRowSize);
    int *down = (int*)malloc(sizeof(int)*matrixRowSize);
    int result = 0;
    int curup, curdown, tmp;
    int i, j;
    for (i = 0; i < matrixRowSize; i++)
    {
        left[i] = up[i] = down[i] = -1;
    }
    for (i = 0; i < matrixColSize; i++)
    {
        curup = curdown = 0;
        for (j = 0; j < matrixRowSize; j++)
        {
            if (matrix[j][i] == '0')
            {
                curup = curdown = j;
                left[j] = up[j] = down[j] = -1;
            }
            else
            {
                if (matrix[curup][i] == '0')
                {
                    curup++;
                }
                while (curdown < j || (curdown < matrixRowSize && matrix[curdown][i] == '1'))
                {
                    curdown++;
                }
                if (left[j] == -1)
                {
                    left[j] = i;
                    up[j] = curup;
                    down[j] = curdown;
                }
                else
                {
                    if (curup > up[j])
                    {
                        up[j] = curup;
                    }
                    if (curdown < down[j])
                    {
                        down[j] = curdown;
                    }
                }
                tmp = (down[j]-up[j])*(i-left[j]+1);
                if (tmp > result)
                {
                    result = tmp;
                }
            }
        }
    }
    return result;
}