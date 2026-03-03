Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.
Input:
- First line: integer n (number of operations)
- Next n lines: operation type and value (if applicable)
  - 1 value: push value
  - 2: pop
  - 3: display
Output:
- For display: print stack elements from top to bottom
- For pop: print popped element or 'Stack Underflow'
Example:
Input:
5
1 10
1 20
3
2
3
Output:
20 10
20
10

Answer:
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int choice, value;

        scanf("%d", &choice);

        if (choice == 1) {
            scanf("%d", &value);
            push(value);
        } 
        else if (choice == 2) {
            pop();
        } 
        else if (choice == 3) {
            display();
        }
    }

    return 0;
}

Problem2:Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
Example 1:
Input: s = "()"
Output: true
Example 2:
Input: s = "()[]{}"
Output: true
Example 3:
Input: s = "(]"
Output: false
Example 4:
Input: s = "([])"
Output: true
Example 5:
Input: s = "([)]"
Output: false
Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

Answer:
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10000

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    if (top == -1)
        return '\0';
    return stack[top--];
}

bool isValid(char *s) {
    top = -1;
    
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } 
        else {
            if (top == -1)   
                return false;

            char popped = pop();

            if ((ch == ')' && popped != '(') ||
                (ch == '}' && popped != '{') ||
                (ch == ']' && popped != '[')) {
                return false;
            }
        }
    }

    return top == -1;
}

int main() {
    char s[MAX];
    scanf("%s", s);

    if (isValid(s))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
