char* convert(char* s, int numRows) {
    if (numRows == 1) return s;
    const unsigned len = strlen(s);
    char *result = (char*)malloc(sizeof(char)*(len+1));
    result[len] = '\0';
    unsigned int i, j, k = (numRows<<1)-2, m = 0;
    for (i = 0; i < len; i += k)
    {
        result[m++] = s[i];
    }
    for (i = 1; i < numRows-1; i++)
    {
        for (j = i; j < len; j += k)
        {
            result[m++] = s[j];
            if (j+k-i-i < len)
            {
                result[m++] = s[j+k-i-i];
            }
        }
    }
    for (i = numRows-1; i < len; i += k)
    {
        result[m++] = s[i];
    }
    return result;
}