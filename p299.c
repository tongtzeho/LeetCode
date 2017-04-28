char* getHint(char* secret, char* guess) {
    int countsecret[10] = {0};
    int countguess[10] = {0};
    int bull = 0;
    int i;
    for (i = 0; secret[i] != '\0'; i++)
    {
        if (secret[i] == guess[i])
        {
            bull++;
        }
        else
        {
            countsecret[secret[i]-'0']++;
            countguess[guess[i]-'0']++;
        }
    }
    int cow = 0;
    for (i = 0; i < 10; i++)
    {
        if (countsecret[i] <= countguess[i]) cow += countsecret[i];
        else cow += countguess[i];
    }
    char *result = (char*)malloc(sizeof(char)*10);
    sprintf(result, "%dA%dB", bull, cow);
    return result;
}
