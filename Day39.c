Problem1:Implement a Min Heap using an array where the smallest element is always at the root.
Supported Operations:
- insert x
- extractMin
- peek
Input Format:
- First line contains integer N
- Next N lines contain heap operations
Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed
Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek
Output:
10
10
30

Answer:
#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int index){
    while(index > 0){
        int parent = (index - 1) / 2;
        if(heap[parent] > heap[index]){
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(int index){
    int left, right, smallest;

    while(1){
        left = 2*index + 1;
        right = 2*index + 2;
        smallest = index;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != index){
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

void insert(int x){
    heap[size] = x;
    heapifyUp(size);
    size++;
}

int extractMin(){
    if(size == 0)
        return -1;

    int min = heap[0];
    heap[0] = heap[size-1];
    size--;
    heapifyDown(0);
    return min;
}

// Peek operation
int peek(){
    if(size == 0)
        return -1;
    return heap[0];
}

int main(){
    int N, x;
    char op[20];

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%s", op);

        if(strcmp(op, "insert") == 0){
            scanf("%d", &x);
            insert(x);
        }
        else if(strcmp(op, "extractMin") == 0){
            printf("%d\n", extractMin());
        }
        else if(strcmp(op, "peek") == 0){
            printf("%d\n", peek());
        }
    }

    return 0;
}

Problem2:Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:
Input: nums = [1], k = 1
Output: [1]
Example 3:
Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
Output: [1,2]
Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

Answer:
#include <stdio.h>
#include <stdlib.h>

#define OFFSET 10000
#define RANGE 20001

int main() {
    int n, k;

    scanf("%d", &n);

    int nums[n];
    for(int i=0;i<n;i++)
        scanf("%d",&nums[i]);

    scanf("%d",&k);

    int freq[RANGE] = {0};

    for(int i=0;i<n;i++)
        freq[nums[i] + OFFSET]++;

    int *bucket[n+1];
    int bucketSize[n+1];

    for(int i=0;i<=n;i++){
        bucket[i] = (int*)malloc(n * sizeof(int));
        bucketSize[i] = 0;
    }

    
    for(int i=0;i<RANGE;i++){
        if(freq[i] > 0){
            int f = freq[i];
            bucket[f][bucketSize[f]++] = i - OFFSET;
        }
    }

    int count = 0;
    for(int i=n;i>=0 && count<k;i--){
        for(int j=0;j<bucketSize[i] && count<k;j++){
            printf("%d ", bucket[i][j]);
            count++;
        }
    }

    return 0;
}
