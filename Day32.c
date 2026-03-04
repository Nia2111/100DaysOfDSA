Problem1: Implement push and pop operations on a stack and verify stack operations.
Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)
Output:
- Print remaining stack elements from top to bottom
Example:
Input:
5
10 20 30 40 50
2
Output:
30 20 10

Answer:
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

int main() {
    int n, m;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        push(value);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        pop();
    }

    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}

Problem2:Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:
MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
Example 1:
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]
Output
[null,null,null,null,-3,null,0,-2]
Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); 
minStack.pop();
minStack.top();    
minStack.getMin(); 
Constraints:
-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.

Answer:
#include <stdio.h>
#include <stdlib.h>

#define MAX 30000

typedef struct {
    int stack[MAX];
    int minStack[MAX];
    int top;
} MinStack;

void initMinStack(MinStack* obj) {
    obj->top = -1;
}

void push(MinStack* obj, int val) {
    obj->top++;
    obj->stack[obj->top] = val;

    if (obj->top == 0) {
        obj->minStack[obj->top] = val;
    } else {
        if (val < obj->minStack[obj->top - 1])
            obj->minStack[obj->top] = val;
        else
            obj->minStack[obj->top] = obj->minStack[obj->top - 1];
    }
}

void pop(MinStack* obj) {
    if (obj->top >= 0)
        obj->top--;
}

int top(MinStack* obj) {
    return obj->stack[obj->top];
}

int getMin(MinStack* obj) {
    return obj->minStack[obj->top];
}
