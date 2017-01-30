char* licenseKeyFormatting(char* S, int K) {
    unsigned maxlen = 24100;
    char *result = (char*)malloc(sizeof(char)*maxlen);
    result[--maxlen] = '\0';
    unsigned j = K;
    for (int i = strlen(S)-1; i >= 0; i--)
    {
        if (S[i] != '-')
        {
            if (S[i] >= 'a' && S[i] <= 'z') S[i] -= 32;
            if (j == 0)
            {
                result[--maxlen] = '-';
                j = K;
            }
            result[--maxlen] = S[i];
            j--;
        }
    }
    return result+maxlen;
}