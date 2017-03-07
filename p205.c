bool isIsomorphic(char* s, char* t) {
    int indexs[128], indext[128];
    int appear[128] = {0};
    int charnum = 0;
    int i;
    int l1 = strlen(s);
    if (strlen(t) != l1) return false;
    for (i = 0; i < 128; i++)
    {
        indexs[i] = indext[i] = -1;
    }
    for (i = 0; i < l1; i++)
    {
        if (indexs[s[i]] != indext[t[i]]) return false;
        if (indexs[s[i]] == -1)
        {
            indexs[s[i]] = charnum;
            indext[t[i]] = charnum;
            appear[charnum++] = 1;
        }
        else
        {
            appear[s[i]]++;
        }
    }
    return true;
}
