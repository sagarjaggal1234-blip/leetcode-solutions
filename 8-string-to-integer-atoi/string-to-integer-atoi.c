#include <limits.h>

int myAtoi(char* s) {
    int i = 0;
    int sign = 1;
    long result = 0;

    // 1. Skip leading spaces
    while (s[i] == ' ') {
        i++;
    }

    // 2. Check sign
    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }

    // 3. Convert digits
    while (s[i] >= '0' && s[i] <= '9') {
        result = result * 10 + (s[i] - '0');

        // 4. Check overflow
        if (sign == 1 && result > INT_MAX) {
            return INT_MAX;
        }

        if (sign == -1 && -result < INT_MIN) {
            return INT_MIN;
        }

        i++;
    }

    return (int)(sign * result);
}
    
