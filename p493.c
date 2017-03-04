int *temp;

int f(int *arr, int left, int right) {
    if (right-left == 1) return 0;
    int mid = (left+right)>>1;
    int ret = f(arr, left, mid)+f(arr, mid, right);
    int i, i1 = left, i2 = mid;
    for (i1 = left; i1 < mid; i1++)
    {
        while (i2 < right && (long long)arr[i1] > ((((long long)arr[i2]) << 1)))
        {
            i2++;
        }
        ret += i2-mid;
        if (i2 == right)
        {
            ret += (mid-i1-1)*(right-mid);
            break;
        }
    }
    i1 = left;
    i2 = mid;
    for (i = left; i < right; i++)
    {
        if (i2 == right || (i1 < mid && arr[i1] <= arr[i2]))
        {
            temp[i] = arr[i1++];
        }
        else
        {
            temp[i] = arr[i2++];
        }
    }
    for (i = left; i < right; i++)
    {
        arr[i] = temp[i];
    }
    return ret;
}

int reversePairs(int* nums, int numsSize) {
    if (!numsSize) return 0;
    temp = (int*)malloc(sizeof(int)*numsSize);
    return f(nums, 0, numsSize);
}