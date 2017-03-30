int addDigits(int num) {
    if (!num) return 0;
    register i = num % 9;
    if (i == 0) return 9;
    return i;
}
