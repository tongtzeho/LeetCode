int lengthLongestPath(char* input) {
    if (!input || !input[0]) return 0;
    unsigned i = 0, j, k, l, depth, result = 0;
    while (input[i])
    {
        j = i;
        while (input[j] == '\t')
        {
            j++;
        }
        depth = j-i;
        bool isfile = false;
        k = j+1;
        while (input[k] != '\n' && input[k] != '\0')
        {
            if (input[k] == '.')
            {
                isfile = true;
            }
            k++;
        }
        i = k;
        if (input[i] == '\n')
        {
            i++;
        }
        if (!isfile)
        {
            l = k-j+1;
            if (depth)
            {
                l += (((unsigned)(unsigned char)input[(depth-1)<<1])<<8)+(unsigned)(unsigned char)input[((depth-1)<<1)+1];
            }
            input[depth<<1] = (unsigned char)(l>>8);
            input[(depth<<1)+1] = (unsigned char)l;
        }
        else
        {
            if (depth)
            {
                l = (((unsigned)(unsigned char)input[(depth-1)<<1])<<8)+(unsigned)(unsigned char)input[((depth-1)<<1)+1]+k-j;
            }
            else
            {
                l = k-j;
            }
            if (l > result)
            {
                result = l;
            }
        }
    }
    return result;
}