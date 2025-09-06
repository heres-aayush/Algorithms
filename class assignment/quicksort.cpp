#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10  

int comparison_count = 0;  

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int lomuto_partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparison_count++;  
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = lomuto_partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void generate_input_file() {
    FILE *file = fopen("input.txt", "w");
    if (file == NULL) return;

    srand(time(0));  
    for (int i = 0; i < SIZE; i++) {
        fprintf(file, "%d ", rand() % 100);  
    }
    fclose(file);
}

void read_input_file(int arr[], int *size) {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) return;

    *size = 0;
    while (fscanf(file, "%d", &arr[*size]) != EOF) {
        (*size)++;
    }
    fclose(file);
}

void write_output_file(int arr[], int size) {
    FILE *file = fopen("output.txt", "w");
    if (file == NULL) return;

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    fclose(file);
}

int main() {
    generate_input_file();  

    int arr[SIZE], size = 0;
    read_input_file(arr, &size);  

    quicksort(arr, 0, size - 1);  

    write_output_file(arr, size);  

    printf("Sorting complete. Check output.txt for results.\n");
    printf("Total comparisons made: %d\n", comparison_count);  

    return 0;
}
