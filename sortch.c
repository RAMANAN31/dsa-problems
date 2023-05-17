#include <stdio.h>

void sortArray(char arr[], int n) {
    int aCount = 0, bCount = 0, cCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 'a') aCount++;
        else if (arr[i] == 'b') bCount++;
        else cCount++;
    }
    int i = 0;
    while (aCount--) arr[i++] = 'a';
    while (bCount--) arr[i++] = 'b';
    while (cCount--) arr[i++] = 'c';
}

int main() {
    char arr[] = {'a', 'b', 'b', 'a', 'b', 'c', 'a', 'c', 'a', 'a', 'a', 'b'};
    int n = sizeof(arr) / sizeof(arr[0]);
    sortArray(arr, n);
    for (int i = 0; i < n; i++)
        printf("%c ", arr[i]);
    return 0;
}
