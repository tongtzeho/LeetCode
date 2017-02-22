int evalRPN(char** tokens, int tokensSize) {
    int *stack = (int*)malloc(sizeof(int)*((tokensSize+1)>>1));
    int stacksize = 0;
    int i, j;
    for (i = 0; i < tokensSize; i++)
    {
        if (tokens[i][0] >= '0' && tokens[i][0] <= '9')
        {
            stack[stacksize] = tokens[i][0]-'0';
            for (j = 1; tokens[i][j] != '\0'; j++)
            {
                stack[stacksize] = (stack[stacksize]<<3)+(stack[stacksize]<<1)+tokens[i][j]-'0';
            }
            stacksize++;
        }
        else if (tokens[i][0] == '-' && tokens[i][1] != '\0')
        {
            stack[stacksize] = tokens[i][1]-'0';
            for (j = 2; tokens[i][j] != '\0'; j++)
            {
                stack[stacksize] = (stack[stacksize]<<3)+(stack[stacksize]<<1)+tokens[i][j]-'0';
            }
            stack[stacksize] = -stack[stacksize];
            stacksize++;
        }
        else
        {
            if (tokens[i][0] == '+') stack[stacksize-2] += stack[stacksize-1];
            else if (tokens[i][0] == '-') stack[stacksize-2] -= stack[stacksize-1];
            else if (tokens[i][0] == '*') stack[stacksize-2] *= stack[stacksize-1];
            else stack[stacksize-2] /= stack[stacksize-1];
            stacksize--;
        }
    }
    return stack[0];
}