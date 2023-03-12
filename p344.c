void reverseString(char* s, int sSize){
    int halfSize = sSize >> 1;
    for (int i = 0; i < halfSize; ++i)
    {
        char temp = s[i];
        s[i] = s[sSize - 1 - i];
        s[sSize - 1 - i] = temp;
    }
}