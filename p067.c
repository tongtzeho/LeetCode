char* addBinary(char* a, char* b) {
    int l1 = strlen(a);
    int l2 = strlen(b);
    int l3 = l1+1;
    if (l2 > l1) l3 = l2+1;
    int add = 0;
    int digit1, digit2;
    char *result = (char*)malloc(sizeof(char)*(l3+1));
    result[l3] = '\0';
    while (l1 > 0 || l2 > 0)
    {
        if (l1 > 0) digit1 = a[--l1]-'0';
        else digit1 = 0;
        if (l2 > 0) digit2 = b[--l2]-'0';
        else digit2 = 0;
        result[--l3] = ((digit1+digit2+add)&1)+'0';
        add = (digit1+digit2+add)>>1;
    }
    if (add) result[--l3] = '1';
    return result+l3;
}