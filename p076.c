char* minWindow(char* s, char* t) {
    int limit[128] = {0};
    int cur[128] = {0};
    unsigned pos = 0, substrlen = 0;
    unsigned slen = strlen(s), tlen = strlen(t), tmplen;
    if (!tlen) return "";
    unsigned to = 0, i;
    unsigned equallessthan0 = 0;
    for (i = 0; i < tlen; i++)
    {
        limit[t[i]]++;
    }
    for (i = 0; i < 128; i++)
    {
        cur[i] = limit[i];
        if (!cur[i]) equallessthan0++;
    }
    for (i = 0; i < slen; i++)
    {
        cur[s[i]]--;
        if (!cur[s[i]])
        {
            equallessthan0++;
            if (equallessthan0 == 128)
            {
                substrlen = i+1;
                to = i;
                break;
            }
        }
    }
    if (i == slen) return "";
    for (i = 0; i < slen-1; i++)
    {
        cur[s[i]]++;
        if (cur[s[i]] > 0)
        {
            equallessthan0--;
            for (to++; to < slen; to++)
            {
                cur[s[to]]--;
                if (!cur[s[to]])
                {
                    equallessthan0++;
                    if (equallessthan0 == 128)
                    {
                        tmplen = to-i;
                        if (tmplen < substrlen)
                        {
                            pos = i+1;
                            substrlen = tmplen;
                        }
                        break;
                    }
                }
            }
            if (equallessthan0 < 128)
            {
                break;
            }
        }
        else
        {
            tmplen = to-i;
            if (tmplen < substrlen)
            {
                pos = i+1;
                substrlen = tmplen;
            }
        }
    }
    s[pos+substrlen] = '\0';
    return s+pos;
}