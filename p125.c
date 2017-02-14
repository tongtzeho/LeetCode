bool isPalindrome(char* s) {
    int len = 0;
    int add = 'a'-'A';
    int i, j;
    for (i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            s[len++] = s[i];
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[len++] = s[i]+add;
        }
    }
    if (!len) return true;
    i = (len-1) >> 1;
    j = len >> 1;
    for ( ; i >= 0; i--, j++)
    {
        if (s[i] != s[j]) return false;
    }
    return true;
}
