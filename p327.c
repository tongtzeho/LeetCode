int *leftsum, *rightsum, *temp, result, sum;

void f(const int *arr, const int l, const int r, const int lower, const int upper) {
    if (r-l == 1)
    {
        if (arr[l] >= lower && arr[l] <= upper)
        {
            result++;
        }
        return;
    }
    int mid = (l+r)>>1;
    f(arr, l, mid, lower, upper);
    f(arr, mid, r, lower, upper);
    int i, j, k;
    int maxindex = r-1;
    int minindex = maxindex;
    for (i = l; i < mid; i++)
    {
        while (maxindex >= mid && rightsum[i]+leftsum[maxindex]-sum > upper)
        {
            maxindex--;
        }
        if (maxindex < mid) break;
        if (rightsum[i]+leftsum[maxindex]-sum < lower) continue;
        if (maxindex < minindex)
        {
            minindex = maxindex;
        }
        while (minindex >= mid && rightsum[i]+leftsum[minindex]-sum >= lower)
        {
            minindex--;
        }
        result += maxindex-minindex;
    }
    k = i = l;
    j = mid;
    while (k < r)
    {
        if (j == r || (i < mid && leftsum[i] < leftsum[j]))
        {
            temp[k++] = leftsum[i++];
        }
        else
        {
            temp[k++] = leftsum[j++];
        }
    }
    for (k = l; k < r; k++)
    {
        leftsum[k] = temp[k];
    }
    k = i = l;
    j = mid;
    while (k < r)
    {
        if (j == r || (i < mid && rightsum[i] < rightsum[j]))
        {
            temp[k++] = rightsum[i++];
        }
        else
        {
            temp[k++] = rightsum[j++];
        }
    }
    for (k = l; k < r; k++)
    {
        rightsum[k] = temp[k];
    }
}

int countRangeSum(int* nums, int numsSize, int lower, int upper) {
    int size = numsSize;
    result = 0;
    if (!size) return 0;
    leftsum = (int*)malloc(sizeof(int)*size);
    rightsum = (int*)malloc(sizeof(int)*size);
    temp = (int*)malloc(sizeof(int)*size);
    sum = 0;
    leftsum[0] = nums[0];
    int i;
    for (i = 1; i < numsSize; i++)
    {
        leftsum[i] = leftsum[i-1]+nums[i];
    }
    sum = leftsum[numsSize-1];
    rightsum[numsSize-1] = nums[numsSize-1];
    for (i = numsSize-2; i >= 0; i--)
    {
        rightsum[i] = rightsum[i+1]+nums[i];
    }
    f(nums, 0, size, lower, upper);
    return result;    
}