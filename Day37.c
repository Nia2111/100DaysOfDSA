Problem1:Implement a Priority Queue using an array. An element with smaller value has higher priority.
Supported Operations:
- insert x
- delete
- peek
Input Format:
- First line contains integer N
- Next N lines contain operations
Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty
Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek
Output:
10
20

Answer:
#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

void insert(int x) {
    if(size == MAX){
        return;
    }

    int i = size - 1;

    while(i >= 0 && pq[i] > x){
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = x;
    size++;
}

void delete() {
    if(size == 0){
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[0]);

    for(int i = 1; i < size; i++){
        pq[i - 1] = pq[i];
    }

    size--;
}

void peek() {
    if(size == 0){
        printf("-1\n");
    }
    else{
        printf("%d\n", pq[0]);
    }
}

int main() {
    int n, x;
    char op[10];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%s", op);

        if(strcmp(op, "insert") == 0){
            scanf("%d", &x);
            insert(x);
        }
        else if(strcmp(op, "delete") == 0){
            delete();
        }
        else if(strcmp(op, "peek") == 0){
            peek();
        }
    }

    return 0;
}

Problem2:You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.
You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.  
Implement the KthLargest class:
KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
Example 1:
Input:
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output: [null, 4, 5, 5, 8, 8]
Explanation:
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3); // return 4
kthLargest.add(5); // return 5
kthLargest.add(10); // return 5
kthLargest.add(9); // return 8
kthLargest.add(4); // return 8
Example 2:
Input:
["KthLargest", "add", "add", "add", "add"]
[[4, [7, 7, 7, 7, 8, 3]], [2], [10], [9], [9]]
Output: [null, 7, 7, 7, 8]
Explanation:
KthLargest kthLargest = new KthLargest(4, [7, 7, 7, 7, 8, 3]);
kthLargest.add(2); // return 7
kthLargest.add(10); // return 7
kthLargest.add(9); // return 7
kthLargest.add(9); // return 8
Constraints:
0 <= nums.length <= 104
1 <= k <= nums.length + 1
-104 <= nums[i] <= 104
-104 <= val <= 104
At most 104 calls will be made to add.

Answer:
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *heap;
    int size;
    int k;
} KthLargest;

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(KthLargest *obj, int i){
    while(i > 0){
        int parent = (i-1)/2;
        if(obj->heap[parent] > obj->heap[i]){
            swap(&obj->heap[parent], &obj->heap[i]);
            i = parent;
        } else break;
    }
}

void heapifyDown(KthLargest *obj, int i){
    while(1){
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if(left < obj->size && obj->heap[left] < obj->heap[smallest])
            smallest = left;

        if(right < obj->size && obj->heap[right] < obj->heap[smallest])
            smallest = right;

        if(smallest != i){
            swap(&obj->heap[i], &obj->heap[smallest]);
            i = smallest;
        } else break;
    }
}

void insertHeap(KthLargest *obj, int val){
    obj->heap[obj->size] = val;
    obj->size++;
    heapifyUp(obj, obj->size - 1);
}

void removeMin(KthLargest *obj){
    obj->heap[0] = obj->heap[obj->size - 1];
    obj->size--;
    heapifyDown(obj, 0);
}

KthLargest* KthLargestCreate(int k, int* nums, int numsSize){
    KthLargest *obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = (int*)malloc(sizeof(int)*(numsSize + 10000));
    obj->size = 0;
    obj->k = k;

    for(int i=0;i<numsSize;i++){
        insertHeap(obj, nums[i]);
        if(obj->size > k)
            removeMin(obj);
    }
    return obj;
}

int add(KthLargest* obj, int val){
    insertHeap(obj, val);

    if(obj->size > obj->k)
        removeMin(obj);

    return obj->heap[0];
}

int main(){
    int nums[] = {4,5,8,2};
    int k = 3;

    KthLargest *obj = KthLargestCreate(k, nums, 4);

    printf("%d\n", add(obj,3));
    printf("%d\n", add(obj,5));
    printf("%d\n", add(obj,10));
    printf("%d\n", add(obj,9));
    printf("%d\n", add(obj,4));

    return 0;
}
