#include <cstdio>
#include <cstdlib>
using namespace std;

int totalComparisons = 0;
int permutationCount = 0;
int comparisons = 0;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void processPermutation(int arr[], int n, FILE *inputFile, FILE *outputFile) {
    for (int i = 0; i < n; i++) {
        fprintf(inputFile, "%d ", arr[i]);
    }
    fprintf(inputFile, "\n");
    int *temp = new int[n];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    comparisons = 0;
    quickSort(temp, 0, n - 1);
    for (int i = 0; i < n; i++) {
        fprintf(outputFile, "%d ", temp[i]);
    }
    fprintf(outputFile, "\n");
    printf("Permutation %d sorted with %d comparisons.\n", permutationCount + 1, comparisons);
    totalComparisons += comparisons;
    permutationCount++;
    delete [] temp;
}

void generatePermutations(int arr[], int start, int n, FILE *inputFile, FILE *outputFile) {
    if (start == n) {
        processPermutation(arr, n, inputFile, outputFile);
        return;
    }
    for (int i = start; i < n; i++) {
        swap(arr[start], arr[i]);
        generatePermutations(arr, start + 1, n, inputFile, outputFile);
        swap(arr[start], arr[i]);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return EXIT_FAILURE;
    }
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    FILE *inputFile = fopen("input.txt", "w");
    if (!inputFile) {
        perror("Failed to open input.txt");
        delete [] arr;
        return EXIT_FAILURE;
    }
    FILE *outputFile = fopen("output.txt", "w");
    if (!outputFile) {
        perror("Failed to open output.txt");
        fclose(inputFile);
        delete [] arr;
        return EXIT_FAILURE;
    }
    generatePermutations(arr, 0, n, inputFile, outputFile);
    if (permutationCount > 0) {
        double average = (double)totalComparisons / permutationCount;
        printf("Total permutations processed: %d\n", permutationCount);
        printf("Average comparisons: %.2f\n", average);
    } else {
        printf("No permutations processed.\n");
    }
    delete [] arr;
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
