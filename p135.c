int candy(int* ratings, int ratingsSize) {
    if (!ratingsSize) return 0;
    if (ratingsSize == 1) return 1;
    int *result = (int*)malloc(sizeof(int)*ratingsSize);
    int i, j, sum = 0;
    for (i = 0; i < ratingsSize; i++)
    {
        result[i] = 1;
    }
    if (ratings[0] <= ratings[1])
    {
        i = 1;
        while (i < ratingsSize && ratings[i] > ratings[i-1])
        {
            result[i] = i+1;
            i++;
        }
    }
    for (i = 1; i < ratingsSize-1; i++)
    {
        if (ratings[i] <= ratings[i-1] && ratings[i] <= ratings[i+1])
        {
            j = 1;
            while (i+j < ratingsSize && ratings[i+j] > ratings[i+j-1])
            {
                result[i+j] = j+1;
                j++;
            }
            j = 1;
            while (i-j >= 0 && ratings[i-j+1] < ratings[i-j])
            {
                if (j+1 > result[i-j]) result[i-j] = j+1;
                j++;
            }
        }
    }
    if (ratings[ratingsSize-1] <= ratings[ratingsSize-2])
    {
        i = 1;
        while (ratingsSize-1-i >= 0 && ratings[ratingsSize-i] < ratings[ratingsSize-1-i])
        {
            if (i+1 > result[ratingsSize-1-i]) result[ratingsSize-1-i] = i+1;
            i++;
        }
    }
    for (i = 0; i < ratingsSize; i++)
    {
        sum += result[i];
    }
    return sum;
}