#include<stdio.h>
#include<stdlib.h>

typedef struct heap {
    int *pos;
    int size;
} minHeap;

minHeap* createMinHeap(int *arr, int size) {
    minHeap *heap = (minHeap *)malloc(sizeof(minHeap));
    heap->pos = (int *)malloc(size * sizeof(int));
    heap->size = size;
    for (int i = 0; i < size; i++)
        heap->pos[i] = arr[i];
    return heap;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void buildMinHeap(minHeap *heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < heap->size && heap->pos[left] < heap->pos[smallest])
        smallest = left;
    if (right < heap->size && heap->pos[right] < heap->pos[smallest])
        smallest = right;
    if (smallest != idx) {
        swap(&heap->pos[idx], &heap->pos[smallest]);
        buildMinHeap(heap, smallest);
    }
}

int extractMin(minHeap *heap) {
    if (heap->size <= 0) return -1;
    int rootVal = heap->pos[0];
    swap(&heap->pos[0], &heap->pos[heap->size - 1]);
    heap->size--;
    buildMinHeap(heap, 0);
    return rootVal;
}

int main() {
    int arr[5] = {4, 5, 6, 2, 1};
    minHeap *heap = createMinHeap(arr, 5);

    // Build the heap bottom-up
    for (int i = (heap->size - 2) / 2; i >= 0; i--)
        buildMinHeap(heap, i);

    int temp[5];
    for (int i = 0; i < 5; i++)
        temp[i] = extractMin(heap);

    for (int i = 0; i < 5; i++)
        printf("%d ", temp[i]);
    
    // Free memory
    free(heap->pos);
    free(heap);
    
    return 0;
}
