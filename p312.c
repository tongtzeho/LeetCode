int maxCoins(int* nums, int numsSize) {
    int *a = (int*)malloc(sizeof(int)*(numsSize+2));
    int **mem = (int**)malloc(sizeof(int*)*(numsSize+1));
    int i, j, k, temp;
    for (i = 0; i < numsSize; i++)
    {
        a[i+1] = nums[i];
    }
    a[0] = a[i+1] = 1;
    for (i = 0; i <= numsSize; i++)
    {
        mem[i] = (int*)malloc(sizeof(int)*(numsSize+2));
        mem[i][i+1] = 0;
    }
    for (i = 2; i <= numsSize+1; i++)
    {
        for (j = 0; j <= numsSize+1-i; j++)
        {
            mem[j][j+i] = 0;
            for (k = j+1; k < i+j; k++)
            {
                temp = a[j]*a[k]*a[j+i]+mem[j][k]+mem[k][j+i];
                if (temp > mem[j][j+i])
                {
                    mem[j][j+i] = temp;
                }
            }
        }
    }
    return mem[0][numsSize+1];
}