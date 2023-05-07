#include <stdio.h>

// Returns the index of the key if found, else -1
int ternarySearch(int arr[], int low, int high, int key) {
    if (low > high) {
        return -1;
    }
    int mid1 = low + (high - low) / 3;
    int mid2 = high - (high - low) / 3;
    if (arr[mid1] == key) {
        return mid1;
    } else if (arr[mid2] == key) {
        return mid2;
    } else if (arr[mid1] > key) {
        return ternarySearch(arr, low, mid1 - 1, key);
    } else if (arr[mid2] < key) {
        return ternarySearch(arr, mid2 + 1, high, key);
    } else {
        return ternarySearch(arr, mid1 + 1, mid2 - 1, key);
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    int index = ternarySearch(arr, 0, n-1, key);
    if (index == -1) {
        printf("Key not found");
    } else {
        printf("Key found at index %d", index);
    }
    return 0;
}
