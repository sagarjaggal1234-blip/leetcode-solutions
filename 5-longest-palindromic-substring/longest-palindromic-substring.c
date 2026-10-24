#include <string.h>

void expand(char *s, int left, int right, int *start, int *maxLen) {
    int n = strlen(s);

    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }

    int len = right - left - 1;

    if (len > *maxLen) {
        *maxLen = len;
        *start = left + 1;
    }
}

char* longestPalindrome(char* s) {
    static char result[1001];

    int n = strlen(s);

    if (n == 0) {
        result[0] = '\0';
        return result;
    }

    int start = 0;
    int maxLen = 1;

    for (int i = 0; i < n; i++) {
        // Odd length palindrome
        expand(s, i, i, &start, &maxLen);

        // Even length palindrome
        expand(s, i, i + 1, &start, &maxLen);
    }

    memcpy(result, s + start, maxLen);
    result[maxLen] = '\0';

    return result;
}