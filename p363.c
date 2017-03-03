int **leftsum;
int *upsum;
int *oldupsum;
int *temparr;

void sort(const int x, const int y) {
    int m = (x+y)>>1;
    int i1 = x, i2 = m;
    int i = x;
    for (i = x; i < y; i++)
    {
        if (i2 == y || (i1 < m && upsum[i1] < upsum[i2]))
        {
            temparr[i] = upsum[i1++];
        }
        else
        {
            temparr[i] = upsum[i2++];
        }
    }
    for (i = x; i < y; i++)
    {
        upsum[i] = temparr[i];
    }
}

int f(const int x, const int y, const int k) {
    if (y-x == 1)
    {
        if (x == 0)
        {
            if (upsum[0] <= k) return upsum[0];
            return -2147483648;
        }
        else
        {
            if (upsum[x]-oldupsum[x-1] <= k) return upsum[x]-oldupsum[x-1];
            return -2147483648;
        }
    }
    int m = (x+y)>>1;
    int result = f(x, m, k);
    int temp = f(m, y, k);
    if (temp <= k && temp > result)
    {
        result = temp;
    }
    if (result == k) return k;
    int i, j;
    int base;
    if (x == 0) base = 0;
    else base = oldupsum[x-1];
    int l = m, r = y-1;
    while (r > l+1)
    {
        int mid = (l+r) >> 1;
        if (upsum[mid]-base < k)
        {
            l = mid;
        }
        else if (upsum[mid]-base > k)
        {
            r = mid-1;
        }
        else return k;
    }
    if (l < y-1 && upsum[l+1]-base <= k)
    {
        l++;
        temp = upsum[l]-base;
        if (temp > result)
        {
            result = temp;
            if (result == k) return k;
        }
    }
    else if (upsum[l]-base <= k)
    {
        temp = upsum[l]-base;
        if (temp > result)
        {
            result = temp;
            if (result == k) return k;
        }
    }
    for (i = x; i < m; i++)
    {
        if (upsum[y-1]-upsum[i] <= k)
        {
            temp = upsum[y-1]-upsum[i];
            if (temp <= k && temp > result)
            {
                result = temp;
                if (result == k) return k;
            }
            break;
        }
    }
    for (j = y-2; j >= m; j--)
    {
        while (i > x && upsum[j]-upsum[i-1] <= k)
        {
            temp = upsum[j]-upsum[i-1];
            if (temp <= k && temp > result)
            {
                result = temp;
                if (result == k) return k;
            }
            i--;
        }
        if (i == x)
        {
            if (i == 0 && upsum[j] <= k)
            {
                temp = upsum[j];
                if (temp <= k && temp > result)
                {
                    result = temp;
                    if (result == k) return k;
                }
                break;
            }
            if (upsum[j]-oldupsum[i-1] <= k)
            {
                temp = upsum[j]-oldupsum[i-1];
                if (temp <= k && temp > result)
                {
                    result = temp;
                    if (result == k) return k;
                }
                break;
            }
        }
        if (i < m) i++;
    }
    sort(x, y);
    return result;
}

int maxSumSubmatrix(int** matrix, int matrixRowSize, int matrixColSize, int k) {
    int i, j, kk;
    int result = -2147483648;
    leftsum = (int**)malloc(sizeof(int*)*matrixRowSize);
    for (i = 0; i < matrixRowSize; i++)
    {
        leftsum[i] = (int*)malloc(sizeof(int)*matrixColSize);
        leftsum[i][0] = matrix[i][0];
        for (j = 1; j < matrixColSize; j++)
        {
            leftsum[i][j] = leftsum[i][j-1]+matrix[i][j];
        }
    }
    upsum = (int*)malloc(sizeof(int)*matrixRowSize);
    oldupsum = (int*)malloc(sizeof(int)*matrixRowSize);
    temparr = (int*)malloc(sizeof(int)*matrixRowSize);
    for (j = 0; j < matrixColSize; j++)
    {
        oldupsum[0] = upsum[0] = leftsum[0][j];
        for (i = 1; i < matrixRowSize; i++)
        {
            oldupsum[i] = upsum[i] = upsum[i-1]+leftsum[i][j];
        }
        int temp = f(0, matrixRowSize, k);
        if (temp <= k && temp > result)
        {
            result = temp;
            if (result == k) return k;
        }
    }
    for (j = 0; j < matrixColSize-1; j++)
        for (kk = j+1; kk < matrixColSize; kk++)
        {
            oldupsum[0] = upsum[0] = leftsum[0][kk]-leftsum[0][j];
            for (i = 1; i < matrixRowSize; i++)
            {
                oldupsum[i] = upsum[i] = upsum[i-1]+leftsum[i][kk]-leftsum[i][j];
            }
            int temp = f(0, matrixRowSize, k);
            if (temp <= k && temp > result)
            {
                result = temp;
                if (result == k) return k;
            }
        }
    return result;
}
