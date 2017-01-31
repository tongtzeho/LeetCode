/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    *returnSize = n;
    if (n <= 0) return NULL;
    char **result = (char**)malloc(sizeof(char*)*n);
    unsigned i, j = 0, k = 0;
    for (i = 1; i <= n; i++) {
        result[i-1] = (char*)malloc(sizeof(char)*11);
        j++;
        k++;
        if (j == 3) {
            if (k == 5) {
                strcpy(result[i-1], "FizzBuzz");
                j = k = 0;
            } else {
                strcpy(result[i-1], "Fizz");
                j = 0;
            }
        } else if (k == 5) {
            strcpy(result[i-1], "Buzz");
            k = 0;
        } else {
            sprintf(result[i-1], "%u", i);
        }
    }
    return result;
}