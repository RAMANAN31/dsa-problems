#include <stdio.h>

// Returns the index of the key if found, else -1
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        } 
        else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;  // key not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    int index = binarySearch(arr, 0, n-1, key);
    if (index == -1) {
        printf("Key not found");
    } else {
        printf("Key found at index %d", index);
    }
    return 0;
}
