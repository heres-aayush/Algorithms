#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10


void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    FILE *inputFile = fopen("input.txt", "w");
    if (inputFile == NULL) {
        printf("Error opening input file for writing!\n");
        return 1;
    }
    
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        fprintf(inputFile, "%d ", (rand() % SIZE));
    }
    fclose(inputFile);
    
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file for reading!\n");
        return 1;
    }

    int arr[SIZE], n = 0;
    while (fscanf(inputFile, "%d", &arr[n]) != EOF) {
        n++;
    }
    fclose(inputFile);

    mergeSort(arr, 0, n - 1);

    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        fprintf(outputFile, "%d ", arr[i]);
    }
    fclose(outputFile);

    printf("Sorting complete. Check output.txt\n");
    return 0;
}
