void reverseWords(char *s) {
    int len = 0, i, j, k;
    char prev = ' ';
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ')
        {
            s[len++] = s[i];
        }
        else if (prev != ' ')
        {
            s[len++] = ' ';
        }
        prev = s[i];
    }
    s[len] = '\0';
    if (s[len-1] == ' ')
    {
        s[--len] = '\0';
    }
    for (i = 0; i < (len>>1); i++)
    {
        prev = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = prev;
    }
    i = 0;
    while (i < len)
    {
        j = i+1;
        while (s[j] != ' ' && s[j] != '\0')
        {
            j++;
        }
        for (k = i; k < ((i+j) >> 1); k++)
        {
            prev = s[k];
            s[k] = s[i+j-k-1];
            s[i+j-k-1] = prev;
        }
        i = j+1;
    }
}