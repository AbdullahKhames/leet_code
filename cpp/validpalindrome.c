#include <stdbool.h>
#include <stdio.h>


#define ZERO 48
#define NINE 57
#define CAPITAL_A 65
#define CAPITAL_Z 90
#define SMALL_A 97
#define SMALL_Z  122

int isAlphaNumeic(char *c, int i) {
    char current = c[i];
    if ((current >= ZERO && current <= NINE) ||
        (current >= SMALL_A && current <= SMALL_Z) ||
        (current >= CAPITAL_A && current <= CAPITAL_Z)) {
            return 1;
    }
    return 0;
}

int isCapital(char c) {
    if ( (c >= CAPITAL_A && c <= CAPITAL_Z)) {
        return 1;
    }
    return 0;
}
int isPalindrome(char* s) {
    int i = 0, size, mid;
    char leftChar, rightChar;
    int j = 0;
    char *temp = s;
    while (temp != NULL && *temp != '\0') {
        j++;
        temp++;
    }
    size = j--;
    temp = s;
    mid = size / 2;
    while (i < size && j >= 0) {
        while (i < size  && !isAlphaNumeic(temp, i)) {
            i++;
        }
        while (j >= 0 && !isAlphaNumeic(temp, j)) {
            j--;
        } 
        if (i < size && isCapital(temp[i]))
        {
            leftChar = temp[i] + 32;
        } else if (i < size) {
            leftChar = temp[i];
        }
        if (j >= 0 && isCapital(temp[j]))
        {
            rightChar = temp[j] + 32;
        } else  if (j >= 0){
            rightChar = temp[j];
        }
        if (leftChar != rightChar) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}
int main() {
    printf("is this (A man, a plan, a canal: Panama) valid palindrome ? %d\n", isPalindrome("A man, a plan, a canal: Panama"));
    printf("is this (race a car) valid palindrome ? %d\n", isPalindrome("race a car"));
    printf("is this (Never a foot too far, even.) valid palindrome ? %d\n", isPalindrome("Never a foot too far, even."));
    printf("is this (,,,,,,,,,,,,acva) valid palindrome ? %d\n", isPalindrome(",,,,,,,,,,,,acva"));
    return 0;
}
