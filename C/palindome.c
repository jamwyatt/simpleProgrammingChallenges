#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>


int ispalindome(int i) {
    char buffer[128];
    int len = snprintf(buffer,sizeof(buffer),"%d", i);
    int left = 0;
    int right=len-1;
    while(left<right) {
        if(buffer[left] != buffer[right])
            return 0;
        left++;
        right--;
        }
    printf("Palindrome: %d\n", i);
    return 1;               // true
    }


int main(int argc, char *argv[]) {
    int largestPalindrome = 0;
    for(int i=100;i<1000; i++) {
        for(int x = 100;x<1000; x++) {
            int candidate = x * i;
            if(ispalindome(candidate) && candidate > largestPalindrome)
                largestPalindrome = candidate;
            }
        }

    printf("Largest palindrome that is the product of two three digit numbers %d\n", largestPalindrome);
    }
