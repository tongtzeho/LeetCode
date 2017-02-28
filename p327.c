int *sum1, *sum2, result;

int comp(const void *a, const void *b )
{
    return *(int*)a-*(int*)b; 
}

void f(const int *arr, const int l, const int r, const int lower, const int upper) {
    if (r-l == 1)
    {
        if (arr[l] >= lower && arr[l] <= upper)
        {
            result++;
        }
        return;
    }
    else if (r-l == 2)
    {
        if (arr[l] >= lower && arr[l] <= upper)
        {
            result++;
        }
        if (arr[r-1] >= lower && arr[r-1] <= upper)
        {
            result++;
        }
        if (arr[l]+arr[r-1] >= lower && arr[l]+arr[r-1] <= upper)
        {
            result++;
        }
        return;
    }
    int mid = (l+r)>>1;
    f(arr, l, mid, lower, upper);
    f(arr, mid, r, lower, upper);
    int i, j;
    sum1[0] = arr[mid-1];
    for (i = 1; i < mid-l; i++)
    {
        sum1[i] = arr[mid-i-1]+sum1[i-1];
    }
    sum2[0] = arr[mid];
    for (i = 1; i < r-mid; i++)
    {
        sum2[i] = arr[mid+i]+sum2[i-1];
    }
    qsort(sum1, mid-l, sizeof(sum1[0]), comp);
    qsort(sum2, r-mid, sizeof(sum2[0]), comp);
    int maxindex = r-mid-1;
    int minindex = maxindex;
    for (i = 0; i < mid-l; i++)
    {
        while (maxindex >= 0 && sum1[i]+sum2[maxindex] > upper)
        {
            maxindex--;
        }
        if (maxindex < 0) break;
        if (sum1[i]+sum2[maxindex] < lower) continue;
        if (maxindex < minindex)
        {
            minindex = maxindex;
        }
        while (minindex >= 0 && sum1[i]+sum2[minindex] >= lower)
        {
            minindex--;
        }
        result += maxindex-minindex;
    }
}

int countRangeSum(int* nums, int numsSize, int lower, int upper) {
    int size = numsSize;
    result = 0;
    if (!size) return 0;
    sum1 = (int*)malloc(sizeof(int)*size);
    sum2 = (int*)malloc(sizeof(int)*size);
    f(nums, 0, size, lower, upper);
    return result;    
}
