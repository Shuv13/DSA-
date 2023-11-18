#include <stdio.h>
#include <stdlib.h>

// Function to get the maximum value in the array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Using counting sort to sort elements based on significant place
void countingSort(int arr[], int n, int place) {
    const int RANGE = 10;
    int output[n];
    int count[RANGE] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / place) % RANGE]++;
    }

    for (int i = 1; i < RANGE; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / place) % RANGE] - 1] = arr[i];
        count[(arr[i] / place) % RANGE]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix sort implementation
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    for (int place = 1; max / place > 0; place *= 10) {
        countingSort(arr, n, place);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    radixSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
