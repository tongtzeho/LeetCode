inline int max(int x, int y)
{
    if (x > y) return x;
    return y;
}

inline int min(int x, int y)
{
    if (x < y) return x;
    return y;
}

int splitArray(int* nums, int numsSize, int m) {
    int *leftsum = (int*)malloc(sizeof(int)*numsSize);
    int i, j, k, left, right, mid;
    leftsum[0] = nums[0];
    for (i = 1; i < numsSize; i++)
    {
        leftsum[i] = nums[i]+leftsum[i-1];
    }
    if (m == 1) return leftsum[i-1];
    int *oldmem = (int*)malloc(sizeof(int)*numsSize);
    int *newmem = (int*)malloc(sizeof(int)*numsSize);
    int *tmp;
    int temp;
    for (j = numsSize-1; j >= m-1; j--)
    {
        oldmem[j] = leftsum[numsSize-1]-leftsum[j-1];
    }
    for (i = 2; i < m; i++)
    {
        for (j = numsSize-i; j >= m-i; j--)
        {
            left = j;
            right = numsSize-i;
            while (right > left)
            {
                mid = (left+right)>>1;
                temp = leftsum[mid]-leftsum[j-1]-oldmem[mid+1];
                if (temp > 0)
                {
                    right = mid;
                }
                else if (temp == 0)
                {
                    left = mid;
                    break;
                }
                else
                {
                    left = mid+1;
                }
            }
            if (left > j)
            {
                newmem[j] = min(max(leftsum[left]-leftsum[j-1], oldmem[left+1]), max(leftsum[left-1]-leftsum[j-1], oldmem[left]));
            }
            else
            {
                newmem[j] = max(leftsum[left]-leftsum[j-1], oldmem[left+1]);
            }
        }
        tmp = oldmem;
        oldmem = newmem;
        newmem = tmp;
    }
    
    left = k;
    right = numsSize-m;
    while (right > left)
    {
        mid = (left+right)>>1;
        temp = leftsum[mid]-oldmem[mid+1];
        if (temp > 0)
        {
            right = mid;
        }
        else if (temp == 0)
        {
            left = mid;
            break;
        }
        else
        {
            left = mid+1;
        }
    }
    if (left > j)
    {
        return min(max(leftsum[left], oldmem[left+1]), max(leftsum[left-1], oldmem[left]));
    }
    else
    {
        return max(leftsum[left], oldmem[left+1]);
    }
}