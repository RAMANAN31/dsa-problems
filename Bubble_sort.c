void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {        
        // Last i elements are already sorted, so we don't need to check them again
        for (j = 0; j < n-i-1; j++) {
            // If current element is greater than the next element, swap them
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
/*The bubbleSort() function takes an integer array arr and its size n as input, and sorts the elements in ascending order using the bubble sort algorithm.
  The outer loop runs n-1 times, since the last element will be sorted after n-1 passes. 
  The inner loop compares adjacent elements and swaps them if they are in the wrong order.
    After each pass of the inner loop,
the largest unsorted element is moved to its correct position at the end of the array.*/










