int titleToNumber(char* s) {
    int len = strlen(s);
    int mul[10] = {1, 26, 676, 17576, 456976, 11881376, 308915776};
    int arr[10] = {0, 26, 702, 18278, 475254, 12356630, 321272406};
    int result =  arr[len-1]+1;
    int i;
    for (i = len-1; i >= 0; i--)
    {
        result += (s[len-1-i]-'A')*mul[i];
    }
    return result;
}
