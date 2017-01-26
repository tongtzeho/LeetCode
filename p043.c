char* multiply(char* num1, char* num2) {
    int l1 = strlen(num1);
    int l2 = strlen(num2);
    if (l1 == 1 && num1[0] == '0') return "0";
    if (l2 == 1 && num2[0] == '0') return "0";
    int l3 = l1+l2;
    char *result = (char*)malloc(sizeof(char)*(l3+1));
    int i, j;
    result[l3] = '\0';
    for (i = 0; i < l3; i++)
    {
        result[i] = '0';
    }
    for (i = l1-1; i >= 0; i--)
    {
        if (num1[i] == '0') continue;
        int add = 0;
        for (j = l2-1; j >= 0; j--)
        {
            int tmp = (num1[i]-'0')*(num2[j]-'0');
            int newdigit = result[i+j+1]-'0'+tmp+add;
            result[i+j+1] = newdigit%10+'0';
            add = newdigit/10;
        }
        result[i] = add+'0';
    }
    if (result[0] == '0') return result+1;
    else return result;
}