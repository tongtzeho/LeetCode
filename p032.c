int longestValidParentheses(char* s) {
    int stacksize = 0;
    int result = 0;
    int len = strlen(s);
    int *left = (int*)malloc(sizeof(int)*len);
    int *valid = (int*)malloc(sizeof(int)*len+1);
    int i, tmp;
    for (i = 0; i < len; i++)
    {
        left[i] = valid[i] = 0;
    }
    for (i = 0; i < len; i++)
    {
        if (s[i] == '(')
        {
            left[stacksize++] = i;
        }
        else
        {
            if (stacksize > 0)
            {
                stacksize--;
                valid[i+1] = i-left[stacksize]+1+valid[left[stacksize]];
                if (valid[i+1] > result)
                {
                    result = valid[i+1];
                }
            }
            else
            {
                if (len-i-1 <= result)
                {
                    break;
                }
            }
        }
    }
    return result;
}