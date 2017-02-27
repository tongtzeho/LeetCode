char* removeDuplicateLetters(char* s) {
    int len = strlen(s);
    if (len == 0) return "";
    char *result = (char*)malloc(sizeof(char)*27);
    bool charselect[26] = {false};
    int i, j, k, pos = 0;
    int out[26];
    int rightpos[26];
    int charnum = 0;
    for (i = 0; i < 26; i++)
    {
        rightpos[i] = -1;
    }
    for (i = len-1; i >= 0; i--)
    {
        if (rightpos[s[i]-'a'] == -1)
        {
            rightpos[s[i]-'a'] = i;
            charnum++;
        }
    }
    int **leftpos = (int**)malloc(sizeof(int*)*len);
    leftpos[len-1] = (int*)malloc(sizeof(int)*26);
    for (i = 0; i < 26; i++)
    {
        leftpos[len-1][i] = -1;
    }
    leftpos[len-1][s[len-1]-'a'] = len-1;
    for (i = len-2; i >= 0; i--)
    {
        leftpos[i] = (int*)malloc(sizeof(int)*26);
        for (j = 0; j < 26; j++)
        {
            leftpos[i][j] = leftpos[i+1][j];
        }
        leftpos[i][s[i]-'a'] = i;
    }
    i = 0;
    while (i < len && charnum > 0)
    {
        if (charselect[s[i]-'a'])
        {
            i++;
        }
        else
        {
            int maxout = -1, minid = 27;
            for (j = 0; j < 26; j++)
            {
                if ((!charselect[j]) && leftpos[i][j] != -1)
                {
                    out[j] = 0;
                    for (k = 0; k < 26; k++)
                    {
                        if ((!charselect[k]) && rightpos[k] != -1 && leftpos[i][j] <= rightpos[k])
                        {
                            out[j]++;
                        }
                    }
                    if (out[j] > maxout)
                    {
                        maxout = out[j];
                        minid = j;
                    }
                }
            }
            result[pos++] = 'a'+minid;
            charselect[minid] = true;
            i = leftpos[i][minid]+1;
            charnum--;
        }
    }
    result[pos++] = '\0';
    return result;
}