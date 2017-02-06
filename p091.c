int numDecodings(char* s) {
    int i;
    int len = strlen(s);
    if (!len) return 0;
    int next2 = 1;
    int next1 = s[len-1] > '0';
    int tmp;
    if (!len) return 0;
    for (i = len-2; i >= 0; i--)
    {
        if (s[i] > '0')
        {
            tmp = next1;
            if (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')) tmp += next2;
        }
        else
        {
            tmp = 0;
        }
        next2 = next1;
        next1 = tmp;
        if ((!next1) && (!next2)) return 0;
    }
    return next1;
}