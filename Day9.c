Problem1: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.
Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)
Output:
- Print the transformed code name after applying the mirror operation
Example:
Input:
hello
Output:
olleh
Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored

Answer:
#include <stdio.h>
#include 

int main() {
    char str[1000];
    scanf("%s", str);
    
    int left = 0;
    int right = strlen(str) - 1;
    
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
    
    printf("%s\n", str);
    return 0;
}

Problem2:Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.
Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
Constraints:
1 <= s.length <= 105
s[i] is a printable ascii character.

Answer:
#include <stdio.h>

void reverseString(char* s, int size) {
    int left = 0, right = size - 1;

    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

int main() {
    char s[] = {'h','e','l','l','o'};
    int size = sizeof(s) / sizeof(s[0]);

    reverseString(s, size);

    printf("Reversed string: ");
    for (int i = 0; i < size; i++) {
        printf("%c", s[i]);
    }
    printf("\n");

    return 0;
}
