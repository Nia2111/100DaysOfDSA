Problem1: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.
Input:
- Postfix expression with operands and operators
Output:
- Print the integer result
Example:
Input:
2 3 1 * + 9 -
Output:
-4
Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.

Answer:
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

int evaluatePostfix(char exp[]) {
    int i = 0;

    while (exp[i] != '\0') {

        if (exp[i] == ' ') {
            i++;
            continue;
        }

        if (isdigit(exp[i])) {
            int num = 0;

            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(num);
        }

        else {
            int b = pop();
            int a = pop();

            switch (exp[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }

            i++;
        }
    }

    return pop();
}

int main() {
    char exp[100];

    printf("Enter postfix expression:\n");
    fgets(exp, sizeof(exp), stdin);

    int result = evaluatePostfix(exp);

    printf("Result: %d\n", result);

    return 0;
}

Problem2:Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
Example 1:
Input: s = "3+2*2"
Output: 7
Example 2:
Input: s = " 3/2 "
Output: 1
Example 3:
Input: s = " 3+5 / 2 "
Output: 5
Constraints:
1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 231 - 1].
The answer is guaranteed to fit in a 32-bit integer.

  
Answer:
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int calculate(char s[]) {
    int stack[100000];
    int top = -1;
    long num = 0;
    char op = '+';

    for (int i = 0; i <= strlen(s); i++) {

        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        if ((!isdigit(s[i]) && s[i] != ' ') || s[i] == '\0') {

            if (op == '+')
                stack[++top] = num;

            else if (op == '-')
                stack[++top] = -num;

            else if (op == '*')
                stack[top] = stack[top] * num;

            else if (op == '/')
                stack[top] = stack[top] / num;

            op = s[i];
            num = 0;
        }
    }

    int result = 0;
    for (int i = 0; i <= top; i++)
        result += stack[i];

    return result;
}

int main() {
    char s[300000];

    printf("Enter expression:\n");
    fgets(s, sizeof(s), stdin);

    printf("Result: %d\n", calculate(s));

    return 0;
}
