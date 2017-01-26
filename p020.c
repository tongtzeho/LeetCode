bool isValid(char* s) {
    int len = strlen(s);
    int stacksize = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            s[stacksize++] = s[i];
        }
        else
        {
            if (stacksize <= 0) return false;
            stacksize--;
            if (s[i] == ')' && s[stacksize] != '(') return false;
            if (s[i] == ']' && s[stacksize] != '[') return false;
            if (s[i] == '}' && s[stacksize] != '{') return false;
        }
    }
    return stacksize == 0;
}