char* longestCommonPrefix(char** strs, int strsSize) {
    if (!strsSize) return "";
    int i, j;
    for (i = 0; ; i++)
    {
        char c = strs[0][i];
        if (c != '\0')
        {
            for (j = 1; j < strsSize; j++)
            {
                if (strs[j][i] != c)
                {
                    strs[0][i] = '\0';
                    return strs[0];
                }
            }
        }
        else
        {
            strs[0][i] = '\0';
            return strs[0];
        }
    }
}