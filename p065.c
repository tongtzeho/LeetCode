bool isNumber(char* s) {
    int len = strlen(s);
    if (!len) return false;
    bool startingblank = true;
    bool endingblank = false;
    bool oper1 = false, oper2 = false;
    bool point = false, e = false;
    bool begin = false;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == ' ')
        {
            if (!startingblank)
            {
                endingblank = true;
            }
        }
        else
        {
            if (endingblank) return false;
            startingblank = false;
            if (s[i] >= '0' && s[i] <= '9')
            {
                begin = true;
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                if (!begin && !oper1)
                {
                    oper1 = true;
                }
                else if (!begin && e && !oper2)
                {
                    oper2 = true;
                }
                else
                {
                    return false;
                }
            }
            else if (s[i] == '.')
            {
                if (point || e)
                {
                    return false;
                }
                oper1 = true;
                point = true;
            }
            else if (s[i] == 'e')
            {
                if (!begin || e)
                {
                    return false;
                }
                begin = false;
                e = true;
            }
            else
            {
                return false;
            }
        }
    }
    return begin;
}