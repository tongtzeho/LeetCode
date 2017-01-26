int romanToInt(char* s) {
    int i = 0;
    int result = 0;
    while (s[i] == 'M')
    {
        result += 1000;
        i++;
    }
    if (s[i] == 'D')
    {
        result += 500;
        i++;
    }
    while (s[i] == 'C')
    {
        if (s[i+1] == 'M')
        {
            result += 900;
            i += 2;
            break;
        }
        else if (s[i+1] == 'D')
        {
            result += 400;
            i += 2;
            break;
        }
        else
        {
            result += 100;
            i++;
        }
    }
    if (s[i] == 'L')
    {
        result += 50;
        i++;
    }
    while (s[i] == 'X')
    {
        if (s[i+1] == 'C')
        {
            result += 90;
            i += 2;
            break;
        }
        else if (s[i+1] == 'L')
        {
            result += 40;
            i += 2;
            break;
        }
        else
        {
            result += 10;
            i++;
        }
    }
    if (s[i] == 'V')
    {
        result += 5;
        i++;
    }
    while (s[i] == 'I')
    {
        if (s[i+1] == 'X')
        {
            result += 9;
            break;
        }
        else if (s[i+1] == 'V')
        {
            result += 4;
            break;
        }
        else
        {
            result++;
            i++;
        }
    }
    return result;
}