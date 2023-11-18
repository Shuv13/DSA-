#include <stdio.h>

int binarySearch(int arr[], int l, int r, int key) {
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == key) {
            return mid;  
        }

        if (arr[mid] < key) {
            l = mid + 1;  
        } else {
            r = mid - 1;  
        }
    }
    return -1;  
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array in sorted order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);

    int index = binarySearch(arr, 0, n - 1, key);

    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
