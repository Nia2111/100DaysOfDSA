Problem: Convert an infix expression to postfix notation using stack.
Input:
- Single line: infix expression (operands are single characters)
Output:
- Print the postfix expression
Example:
Input:
A+B*C
Output:
ABC*+
Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity

Answer:
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int precedence(char x) {
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
        return 3;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;
    
    printf("Enter infix expression: ");
    scanf("%s", infix);

    for(i = 0; infix[i] != '\0'; i++) {
        
        if(isalnum(infix[i])) {  
            postfix[j++] = infix[i];
        }
        else if(infix[i] == '(') {
            push(infix[i]);
        }
        else if(infix[i] == ')') {
            while(stack[top] != '(')
                postfix[j++] = pop();
            pop();
        }
        else {
            while(top != -1 && precedence(stack[top]) >= precedence(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }
    }

    while(top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

Problem2:You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
Evaluate the expression. Return an integer that represents the value of the expression.
Note that:
The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
Example 1:
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
Constraints:
1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

Answer:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int n, i;
    char token[20];

    printf("Enter number of tokens: ");
    scanf("%d", &n);

    printf("Enter tokens:\n");

    for(i = 0; i < n; i++) {
        scanf("%s", token);

        if(strcmp(token, "+") == 0) {
            int b = pop();
            int a = pop();
            push(a + b);
        }
        else if(strcmp(token, "-") == 0) {
            int b = pop();
            int a = pop();
            push(a - b);
        }
        else if(strcmp(token, "*") == 0) {
            int b = pop();
            int a = pop();
            push(a * b);
        }
        else if(strcmp(token, "/") == 0) {
            int b = pop();
            int a = pop();
            push(a / b);
        }
        else {
            push(atoi(token)); 
        }
    }

    printf("Result: %d\n", pop());

    return 0;
}
