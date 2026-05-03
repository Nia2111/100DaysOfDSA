Problem1:Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.

Answer:
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* m1 = *(int**)a;
    int* m2 = *(int**)b;
    return m1[0] - m2[0];
}

void swap(int* heap, int i, int j) {
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void heapifyUp(int* heap, int index) {
    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(heap, index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}

void heapifyDown(int* heap, int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != index) {
        swap(heap, index, smallest);
        heapifyDown(heap, size, smallest);
    }
}

int minMeetingRooms(int** intervals, int intervalsSize) {
    if (intervalsSize == 0) return 0;

    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int* heap = (int*)malloc(intervalsSize * sizeof(int));
    int heapSize = 0;

    heap[heapSize++] = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++) {
        if (heap[0] <= intervals[i][0]) {
            heap[0] = intervals[i][1];
            heapifyDown(heap, heapSize, 0);
        } else {
            heap[heapSize] = intervals[i][1];
            heapifyUp(heap, heapSize);
            heapSize++;
        }
    }

    int result = heapSize;
    free(heap);
    return result;
}

Problem2:Given two arrays start[] and end[] such that start[i] is the starting time of ith meeting and end[i] is the ending time of ith meeting. Return the minimum number of rooms required to attend all meetings.
Note: A person can also attend a meeting if it's starting time is same as the previous meeting's ending time.
Examples:
Input: start[] = [1, 10, 7], end[] = [4, 15, 10]
Output: 1
Explanation: Since all the meetings are held at different times, it is possible to attend all the meetings in a single room.
Input: start[] = [2, 9, 6], end[] = [4, 12, 10]
Output: 2
Explanation: 1st and 2nd meetings at one room but for 3rd meeting one another room required.
Constraints:
1 ≤ start.size() = end.size() ≤ 105
0 ≤ start[i] < end[i] ≤ 106.

Answer:
int minMeetingRooms(int** intervals, int intervalsSize) {
    if (intervalsSize == 0) return 0;

    int* start = (int*)malloc(intervalsSize * sizeof(int));
    int* end = (int*)malloc(intervalsSize * sizeof(int));

    for (int i = 0; i < intervalsSize; i++) {
        start[i] = intervals[i][0];
        end[i] = intervals[i][1];
    }

    qsort(start, intervalsSize, sizeof(int), (__compar_fn_t)strcmp);
    qsort(end, intervalsSize, sizeof(int), (__compar_fn_t)strcmp);

    int rooms = 0, endPtr = 0;
    for (int i = 0; i < intervalsSize; i++) {
        if (start[i] < end[endPtr]) rooms++;
        else endPtr++;
    }

    free(start);
    free(end);
    return rooms;
}
