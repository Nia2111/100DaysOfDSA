Problem1:Implement a Queue using a linked list supporting enqueue and dequeue operations.
Input Format:
- First line contains integer N
- Next N lines contain queue operations
Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue.

Answer:
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

void dequeue() {
    if (front == NULL) {
        printf("-1\n");
        return;
    }

    struct Node* temp = front;
    printf("%d\n", front->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

int main() {
    int N;
    scanf("%d", &N);

    char operation[10];
    int value;

    for (int i = 0; i < N; i++) {
        scanf("%s", operation);

        if (operation[0] == 'e') {  
            scanf("%d", &value);
            enqueue(value);
        } else if (operation[0] == 'd') { 
            dequeue();
        }
    }

    return 0;
}

Problem2:You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.
Return the minimum number of CPU intervals required to complete all tasks.
Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.
Example 2:
Input: tasks = ["A","C","A","B","D","B"], n = 1
Output: 6
Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.
With a cooling interval of 1, you can repeat a task after just one other task.
Example 3:
Input: tasks = ["A","A","A", "B","B","B"], n = 3
Output: 10
Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.
There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.
Constraints:
1 <= tasks.length <= 104
tasks[i] is an uppercase English letter.
0 <= n <= 100.

Answer:
#include <stdio.h>

int leastInterval(char tasks[], int size, int n) {
    int freq[26] = {0};

    for(int i = 0; i < size; i++)
        freq[tasks[i] - 'A']++;

    int maxFreq = 0;
    for(int i = 0; i < 26; i++)
        if(freq[i] > maxFreq)
            maxFreq = freq[i];

    int maxCount = 0;
    for(int i = 0; i < 26; i++)
        if(freq[i] == maxFreq)
            maxCount++;

    int partCount = maxFreq - 1;
    int partLength = n + 1;
    int minIntervals = partCount * partLength + maxCount;

    return (size > minIntervals) ? size : minIntervals;
}

int main() {
    char tasks[] = {'A','A','A','B','B','B'};
    int n = 2;
    int size = sizeof(tasks)/sizeof(tasks[0]);

    printf("%d\n", leastInterval(tasks, size, n));
    return 0;
}
