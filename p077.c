/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 
int *tmp;
int **result;

void f(const int n, const int k, int *index, const int pos, const int val)
{
    if (pos == k)
    {
        for (int i = 0; i < k; i++)
        {
            result[*index][i] = tmp[i];
        }
        (*index)++;
        return;
    }
    for (int i = val; i <= n-k+pos+1; i++)
    {
        tmp[pos] = i;
        f(n, k, index, pos+1, i+1);
    }
}
 
int** combine(int n, int k, int** columnSizes, int* returnSize) {
    if (n == 0)
    {
        (*returnSize) = 0;
        (*columnSizes) = NULL;
        return NULL;
    }
    (*returnSize) = 1;
    int i, j;
    for (i = 1; i <= k; i++)
        (*returnSize) = (*returnSize)*(n-k+i)/i;
    result = (int**)malloc(sizeof(int*)*(*returnSize));
    (*columnSizes) = (int*)malloc(sizeof(int)*(*returnSize));
    if (k == 0)
    {
        for (i = 0; i < *returnSize; i++)
        {
            (*columnSizes)[i] = 0;
        }
        return result;
    }
    else
    {
        for (i = 0; i < *returnSize; i++)
        {
            (*columnSizes)[i] = k;
            result[i] = (int*)malloc(sizeof(int)*k);
        }
    }
    tmp = (int*)malloc(sizeof(int)*k);
    i = 0;
    f(n, k, &i, 0, 1);
    return result;
}

