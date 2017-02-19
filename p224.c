int calculate(char* s) {
    int len = strlen(s);
    int *numstack = (int*)malloc(sizeof(int)*len);
    char *opsstack = (char*)malloc(sizeof(char)*len);
    int stacksize = 0;
    int i;
    int tmp = 0;
    opsstack[stacksize++] = '(';
    for (i = 0; i <= len; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            tmp = (tmp<<3)+(tmp<<1)+s[i]-'0';
        }
        else
        {
            if (i > 0 && s[i-1] >= '0' && s[i-1] <= '9')
            {
                if (opsstack[stacksize-1] == '(')
                {
                    opsstack[stacksize] = '0';
                    numstack[stacksize++] = tmp;
                }
                else if (opsstack[stacksize-1] == '+')
                {
                    numstack[stacksize-2] += tmp;
                    stacksize--;
                }
                else if (opsstack[stacksize-1] == '-')
                {
                    numstack[stacksize-2] -= tmp;
                    stacksize--;
                }
                tmp = 0;
            }
            if (s[i] == '+')
            {
                opsstack[stacksize++] = '+';
            }
            else if (s[i] == '-')
            {
                opsstack[stacksize++] = '-';
            }
            else if (s[i] == '(')
            {
                opsstack[stacksize++] = '(';
            }
            else if (s[i] == ')' || s[i] == '\0')
            {
                opsstack[stacksize-2] = '0';
                numstack[stacksize-2] = numstack[stacksize-1];
                stacksize--;
                if (stacksize >= 3)
                {
                    if (opsstack[stacksize-2] == '+')
                    {
                        numstack[stacksize-3] += numstack[stacksize-1];
                        stacksize -= 2;
                    }
                    else if (opsstack[stacksize-2] == '-')
                    {
                        numstack[stacksize-3] -= numstack[stacksize-1];
                        stacksize -= 2;
                    }
                }
            }
        }
    }
    return numstack[0];
}