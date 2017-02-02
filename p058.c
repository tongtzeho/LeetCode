int lengthOfLastWord(char* s) {
    int i;
    int result = 0;
    bool space = true;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ')
        {
            space = true;
        }
        else
        {
            if (space)
            {
                space = false;
                result = 1;
            }
            else
            {
                result++;
            }
        }
    }
    return result;
}