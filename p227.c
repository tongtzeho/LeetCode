int calculate(char* s) {
    bool isnum = false;
    int i;
    int num = 0;
    int len = strlen(s);
    int *numstack = (int*)malloc(sizeof(int)*((len>>1)+2));
    int *opsstack = (int*)malloc(sizeof(int)*((len>>1)+2));
    int numstacksize = 0;
    for (i = 0; i <= len; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            isnum = true;
            num = num*10+s[i]-'0';
        }
        else
        {
            if (isnum)
            {
                numstack[numstacksize++] = num;
                num = 0;
                isnum = false;
                if (numstacksize > 1 && opsstack[numstacksize-2] >= 2)
                {
                    if (opsstack[numstacksize-2] == 2)
                    {
                        numstack[numstacksize-2] *= numstack[numstacksize-1];
                    }
                    else
                    {
                        numstack[numstacksize-2] /= numstack[numstacksize-1];
                    }
                    numstacksize--;
                }
            }
            if (s[i] == '+')
            {
                opsstack[numstacksize-1] = 0;
            }
            else if (s[i] == '-')
            {
                opsstack[numstacksize-1] = 1;
            }
            else if (s[i] == '*')
            {
                opsstack[numstacksize-1] = 2;
            }
            else if (s[i] == '/')
            {
                opsstack[numstacksize-1] = 3;
            }
        }
    }
    int result = numstack[0];
    for (i = 1; i < numstacksize; i++)
    {
        if (opsstack[i-1] == 0)
        {
            result += numstack[i];
        }
        else
        {
            result -= numstack[i];
        }
    }
    return result;
}
