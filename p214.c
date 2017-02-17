char* shortestPalindrome(char* needle) {
    if (needle == NULL) return NULL;
    int nl = strlen(needle);
    char *haystack = (char*)malloc(sizeof(char)*(nl+nl));
    int *next = (int*)malloc(sizeof(int)*nl);
    next[0] = -1;
    int i, j, k;
    for (i = 0; i < nl; i++)
    {
        haystack[i] = needle[nl-1-i];
    }
    j = 0;
    k = -1;
    while (j < nl-1)
    {
        if (k == -1 || needle[j] == needle[k])
        {
            j++;
            k++;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
    i = j = 0;
    while (i < nl)
    {
        if (j == -1 || haystack[i] == needle[j])
        {
            i++;
            j++;
            if (j == nl) break;
        }
        else
        {
            j = next[j];
        }
    }
    for (i = nl; j < nl; i++, j++)
    {
        haystack[i] = needle[j];
    }
    haystack[i] = '\0';
    return haystack;
}
