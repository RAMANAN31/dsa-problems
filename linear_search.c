#include <stdio.h>

int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;   // Key found at index i
        }
    }
    return -1;          // Key not found
}

int main() {
    int arr[] = {1, 4, 3, 7, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;
    int index = linear_search(arr, n, key);
    if (index == -1) {
        printf("Key not found in array.\n");
    } else {
        printf("Key found at index %d\n", index);
    }
    return 0;
}
