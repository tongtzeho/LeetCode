/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
int *a;
int *b;
int *result;
int *cur;
int **rightfirst1;
int **rightfirst2;

void getrightfirst(int *num, int size, int **arr) {
    int i, j;
    for (i = size-1; i >= 0; i--)
    {
        arr[i] = (int*)malloc(sizeof(int)*10);
        for (j = 0; j < 10; j++)
        {
            if (i == size-1)
            {
                arr[i][j] = size;
            }
            else
            {
                arr[i][j] = arr[i+1][j];
            }
        }
        if (i < size-1)
        {
            arr[i][num[i+1]] = i+1;
        }
    }
}

void select_(int *src, int **mem, int size, int *dest, int destsize) {
    int i = 0, j, k = 0;
    while (k < destsize)
    {
        bool jmp = false;
        for (j = 9; j > src[i]; j--)
        {
            if (mem[i][j] != size && size-mem[i][j]+k >= destsize)
            {
                i = mem[i][j];
                jmp = true;
                break;
            }
        }
        if (!jmp)
        {
            dest[k++] = src[i++];
        }
    }
}

int cmp(int *arr1, int *arr2, int size1, int size2, int i1, int i2) {
    while (i1 < size1 && i2 < size2 && arr1[i1] == arr2[i2])
    {
        i1++;
        i2++;
    }
    if (i1 == size1) return -1;
    if (i2 == size2) return 1;
    if (arr1[i1] > arr2[i2]) return 1;
    return -1;
}

int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize) {
    *returnSize = k;
    if (!k)
    {
        return NULL;
    }
    a = (int*)malloc(sizeof(int)*nums1Size);
    b = (int*)malloc(sizeof(int)*nums2Size);
    int i, j, l;
    result = (int*)malloc(sizeof(int)*k);
    cur = (int*)malloc(sizeof(int)*k);
    rightfirst1 = (int**)malloc(sizeof(int*)*nums1Size);
    rightfirst2 = (int**)malloc(sizeof(int*)*nums2Size);
    getrightfirst(nums1, nums1Size, rightfirst1);
    getrightfirst(nums2, nums2Size, rightfirst2);
    for (i = 0; i < k; i++)
    {
        result[i] = 0;
    }
    int minselect = k-nums2Size;
    if (minselect < 0) minselect = 0;
    for (i = minselect; i <= k && i <= nums1Size; i++)
    {
        if (k-i < 0) break;
        select_(nums1, rightfirst1, nums1Size, a, i);
        select_(nums2, rightfirst2, nums2Size, b, k-i);
        int i1 = 0, i2 = 0;
        bool eql = true;
        for (j = 0; j < k; j++)
        {
            if (cmp(a, b, i, k-i, i1, i2) == 1)
            {
                cur[j] = a[i1++];
            }
            else
            {
                cur[j] = b[i2++];
            }
            if (eql && cur[j] != result[j])
            {
                eql = false;
                if (cur[j] < result[j])
                {
                    break;
                }
            }
            if (!eql)
            {
                result[j] = cur[j];
            }
        }
    }
    return result;
}
